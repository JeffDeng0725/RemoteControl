import socket
from pywinauto import Application
import time

def handle_client(client_socket):
    exe_path = r"C:\Users\dengwenzhe\ResearchJeff\DLL_Examples_240411\DLL Examples\Visual_C\MSVC_Tango.exe"
    
#    exe_path = r"/Users/dengwenzhe/Desktop/ResearchJeff/Camera\ Control/Tango/DLL\ Examples/Visual_C/SourceCode/Release/MSVC_Tango.exe"
    app = Application().start(exe_path)
    time.sleep(5)
    main_window = app.window(title='Tango API Example for Visual C++')

    while True:
        data = client_socket.recv(1024).decode('utf-8')
        if not data:
            break
        
        try:
            x, y = map(float, data.split(','))
            main_window['Edit3'].set_edit_text(str(x))  # 设置X轴输入框
            main_window['Edit4'].set_edit_text(str(y))  # 设置Y轴输入框

            main_window['ConnectButton'].click()
            main_window['Move AbsoluteButton'].click()

            x_position = main_window['Edit7'].get_value()
            y_position = main_window['Edit8'].get_value()

            response = f"{x_position},{y_position}"
            client_socket.send(response.encode('utf-8'))
        except ValueError:
            print("Received invalid data")
            client_socket.send(b"Invalid data")

    client_socket.close()

def main():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('localhost', 9999))
    server.listen(1)
    print("Server listening on port 9999")

    while True:
        client_socket, addr = server.accept()
        print(f"Accepted connection from {addr}")
        handle_client(client_socket)

if __name__ == "__main__":
    main()
