# coding=windows-1252
# =====================================================================
# Example how to use Tango DLL in conjunction with Python version 3.10.5
# =====================================================================
import ctypes
import sys
import re
from ctypes import *  # import ctypes (used to call DLL functions)


m_Tango = cdll.LoadLibrary(r"./Tango_DLL.dll")  # give location of dll (current directory)

if m_Tango == 0:
    print("Error: failed to load DLL")
    sys.exit(0)

# Tango_DLL.dll loaded successfully

if m_Tango.LSX_CreateLSID == 0:
    print("unexpected error. required DLL function CreateLSID() missing")
    sys.exit(0)
# continue only if required function exists

LSID = c_int()
error = int  # value is either DLL or Tango error number if not zero
error = m_Tango.LSX_CreateLSID(byref(LSID))
if error > 0:
    print("Error: " + str(error))
    sys.exit(0)

# OK: got communication ID from DLL (usually 1. may vary with multiple connections)
# keep this LSID in mind during the whole session

if m_Tango.LSX_ConnectSimple == 0:
    print("unexepcted error. required DLL function ConnectSimple() missing")
    sys.exit(0)
# continue only if required function exists

# error = m_Tango.LSX_ConnectSimple(LSID,2,"COM20",57600,0)
# following combination of -1,"" works only for USB but not for RS232 connections 
error = m_Tango.LSX_ConnectSimple(LSID, -1, "", 57600, 0)
if error > 0:
    print("Error: LSX_ConnectSimple " + str(error))
    sys.exit(0)

print("TANGO is now successfully connected to DLL")

# some c-type variables (general purpose usage)
dx = c_double()
dy = c_double()
dz = c_double()
da = c_double()

ca = c_char()
cb = c_char()
ia = c_int()
ba = c_bool()

resp = create_string_buffer(256)
error = m_Tango.LSX_GetDLLVersionString(LSID, resp, 256)
if error > 0:
    print("Error: DLLVersionString " + str(error))
else:
    print("Dll version: " + str(resp.value.decode("ascii")))


inp = c_char_p("?version\r".encode("utf-8"))
resp = create_string_buffer(256)
error = m_Tango.LSX_SendString(LSID, inp, resp, 256, True, 5000)
if error > 0:
    print("Error: SendString " + str(error))
else:
    print(
        'Info: Version ' + str(resp.value.decode("ascii")))


# query actual position (4 axes) (unit depends on GetDimensions)
error = m_Tango.LSX_GetPos(LSID, byref(dx), byref(dy), byref(dz), byref(da))
if error > 0:
    print("Error: GetPos " + str(error))
else:
    print("position = " + str(dx.value) + " " + str(dy.value) + " " + str(dz.value) + " " + str(da.value))

# query actual axes accelerations (unit is m/s²)
error = m_Tango.LSX_GetAccel(LSID, byref(dx), byref(dy), byref(dz), byref(da))
if error > 0:
    print("Error: GetAccel " + str(error))
else:
    print("acceleration = " + str(dx.value) + " " + str(dy.value) + " " + str(dz.value) + " " + str(da.value))

# query pitch factor
error = m_Tango.LSX_GetPitch(LSID, byref(dx), byref(dy), byref(dz), byref(da))
if error > 0:
    print("Error: GetPitch " + str(error))
else:
    print("pitch = " + str(dx.value) + " " + str(dy.value) + " " + str(dz.value) + " " + str(da.value))

# query gear factor
error = m_Tango.LSX_GetGear(LSID, byref(dx), byref(dy), byref(dz), byref(da))
if error > 0:
    print("Error: GetGear " + str(error))
else:
    print("gear = " + str(dx.value) + " " + str(dy.value) + " " + str(dz.value) + " " + str(da.value))

# query motor current (in A)
error = m_Tango.LSX_GetMotorCurrent(LSID, byref(dx), byref(dy), byref(dz), byref(da))
if error > 0:
    print("Error: GetMotorCurrent " + str(error))
else:
    print("motor current = " + str(dx.value) + " " + str(dy.value) + " " + str(dz.value) + " " + str(da.value))

# be careful now and consider axes are moving
# protect your equipment (condensor lenses etc.) from possible collision


# calibrate all axes
error = m_Tango.LSX_Calibrate(LSID)
if error > 0:
    print("Error: Calibrate " + str(error))
else:
    print("Info: calibration done")

# example how to calibrate Z only
error = m_Tango.LSX_CalibrateEx(LSID, 4)
if error > 0:
    print("Error: CalibrateEx " + str(error))
else:
    print("Info: calibration Z done")

# range measure for X axis
error = m_Tango.LSX_RMeasureEx(LSID, 1)
if error > 0:
    print("Error: Range measure " + str(error))
else:
    print("Info: Range measure for X done")

# range measure for Y axis
error = m_Tango.LSX_RMeasureEx(LSID, 2)
if error > 0:
    print("Error: Range measure " + str(error))
else:
    print("Info: Range measure for Y done")


# move center
inp = c_char_p("!moc\r".encode("utf-8"))
resp = create_string_buffer(256)
error = m_Tango.LSX_SendString(LSID, inp, resp, 256, True, 5000)
if error > 0:
    print("Error: SendString " + str(error))
else:
    print(
        'Info: MoveCenter via SendString done: ' + str(resp.value.decode("ascii")))


# send any command
command = "?pos"
inp = c_char_p((command + "\r").encode("utf-8"))

resp = create_string_buffer(256)
error = m_Tango.LSX_SendString(LSID, inp, resp, 256, True, 5000)

if error > 0:
    print("Error: SendString " + str(error))
    # example for differentiating between float responses and ting responses.
    # if float, list will be created to further work with them
else:
    if bool((re.findall('^[\d. \-]+$', str(resp.value.decode("ascii"))))):
        # if response contains only numbers create list of all
        resp_int = [float(e) for e in re.findall('-?\d*\.?\d+', str(resp.value.decode("ascii"))) if e]
        print('Info: SendString done for command: "' + command + '" with  (int) response: ' + str(resp_int))
    else:
        print("The string does not contain only numbers")
        resp_str = str(resp.value.decode("ascii"))
        print('Info: SendString done for command: "' + command + '" with response: "' + resp_str + '"')
