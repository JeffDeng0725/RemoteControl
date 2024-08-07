% loadlibrary('Tango DLL\Tango_DLL.dll','Tango DLL\Tango_DLL.h');

function varargout = mwTango(varargin)
    % MWTANGO MATLAB code for mwTango.fig
    %      MWTANGO, by itself, creates a new MWTANGO or raises the existing
    %      singleton*.
    %
    %      H = MWTANGO returns the handle to a new MWTANGO or the handle to
    %      the existing singleton*.
    %
    %      MWTANGO('CALLBACK',hObject,eventData,handles,...) calls the local
    %      function named CALLBACK in MWTANGO.M with the given input arguments.
    %
    %      MWTANGO('Property','Value',...) creates a new MWTANGO or raises the
    %      existing singleton*.  Starting from the left, property value pairs are
    %      applied to the GUI before mwTango_OpeningFcn gets called.  An
    %      unrecognized property name or invalid value makes property application
    %      stop.  All inputs are passed to mwTango_OpeningFcn via varargin.
    %
    %      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
    %      instance to run (singleton)".
    %
    % See also: GUIDE, GUIDATA, GUIHANDLES

    % Edit the above text to modify the response to help mwTango

    % Last Modified by GUIDE v2.5 13-May-2015 09:37:59

    % Begin initialization code - DO NOT EDIT
    gui_Singleton = 1;
    gui_State = struct('gui_Name',       mfilename, ...
                       'gui_Singleton',  gui_Singleton, ...
                       'gui_OpeningFcn', @mwTango_OpeningFcn, ...
                       'gui_OutputFcn',  @mwTango_OutputFcn, ...
                       'gui_LayoutFcn',  [] , ...
                       'gui_Callback',   []);
    if nargin && ischar(varargin{1})
        gui_State.gui_Callback = str2func(varargin{1});
    end

    if nargout
        [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
    else
        gui_mainfcn(gui_State, varargin{:});
    end
    % End initialization code - DO NOT EDIT

end

% --- Executes just before mwTango is made visible.
function mwTango_OpeningFcn(hObject, eventdata, handles, varargin)
    % This function has no output args, see OutputFcn.
    % hObject    handle to figure
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)
    % varargin   command line arguments to mwTango (see VARARGIN)

    % Choose default command line output for mwTango
    handles.output = hObject;

    % set up the C pointer to the id for the Tango
    handles.idPtr = libpointer('int32Ptr',1);
    calllib('Tango_DLL','LSX_CreateLSID',handles.idPtr);
    
    % connect to the Tango
    calllib('Tango_DLL','LSX_ConnectSimple',handles.idPtr.Value,1,'COM3',57600,1);
    
    % clear the current position
    calllib('Tango_DLL','LSX_ClearPos',handles.idPtr.Value,7);
    
    % create the pointers for the positions
    handles.xPosPtr = libpointer('doublePtr',0);
    handles.yPosPtr = libpointer('doublePtr',0);
    handles.zPosPtr = libpointer('doublePtr',0);
    handles.aPosPtr = libpointer('doublePtr',0);
    
    updatePosition(handles);
    
    % Update handles structure
    guidata(hObject, handles);

    % UIWAIT makes mwTango wait for user response (see UIRESUME)
    % uiwait(handles.figure1);

end

% --- Executes when user attempts to close figure1.
function figure1_CloseRequestFcn(hObject, eventdata, handles)
    % hObject    handle to figure1 (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hint: delete(hObject) closes the figure
    % if the ActiveX control exists, close it out
    
    disp('closing out');
    
    % disconnect from the Tango
    calllib('Tango_DLL','LSX_Disconnect',handles.idPtr.Value);
    calllib('Tango_DLL','LSX_FreeLSID',handles.idPtr.Value);
    
    get(handles.idPtr)
    
    delete(hObject);

end

% --- Outputs from this function are returned to the command line.
function varargout = mwTango_OutputFcn(hObject, eventdata, handles) 
    % varargout  cell array for returning output args (see VARARGOUT);
    % hObject    handle to figure
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Get default command line output from handles structure
    varargout{1} = handles.output;

end


function edit_xPos_Callback(hObject, eventdata, handles)
    % hObject    handle to edit_xPos (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hints: get(hObject,'String') returns contents of edit_xPos as text
    %        str2double(get(hObject,'String')) returns contents of edit_xPos as a double

    handles = setPosition(handles);
    updatePosition(handles);
    
end

% --- Executes during object creation, after setting all properties.
function edit_xPos_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to edit_xPos (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: edit controls usually have a white background on Windows.
    %       See ISPC and COMPUTER.
    if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor','white');
    end

end

function edit_yPos_Callback(hObject, eventdata, handles)
    % hObject    handle to edit_yPos (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hints: get(hObject,'String') returns contents of edit_yPos as text
    %        str2double(get(hObject,'String')) returns contents of edit_yPos as a double

    handles = setPosition(handles);
    updatePosition(handles);
    
end

% --- Executes during object creation, after setting all properties.
function edit_yPos_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to edit_yPos (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: edit controls usually have a white background on Windows.
    %       See ISPC and COMPUTER.
    if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor','white');
    end

end

function edit_zPos_Callback(hObject, eventdata, handles)
    % hObject    handle to edit_zPos (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    % Hints: get(hObject,'String') returns contents of edit_zPos as text
    %        str2double(get(hObject,'String')) returns contents of edit_zPos as a double

    handles = setPosition(handles);
    updatePosition(handles);
    
end

% --- Executes during object creation, after setting all properties.
function edit_zPos_CreateFcn(hObject, eventdata, handles)
    % hObject    handle to edit_zPos (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    empty - handles not created until after all CreateFcns called

    % Hint: edit controls usually have a white background on Windows.
    %       See ISPC and COMPUTER.
    if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
        set(hObject,'BackgroundColor','white');
    end

end

function handles = updatePosition(handles)

    calllib('Tango_DLL','LSX_GetPos',handles.idPtr.Value,handles.xPosPtr,...
        handles.yPosPtr,handles.zPosPtr,handles.aPosPtr);
    
    %handles.xPosPtr.Value
    
    % display the relative positions
    set(handles.edit_xPos,'String',num2str(handles.xPosPtr.Value));
    set(handles.edit_yPos,'String',num2str(handles.yPosPtr.Value));
    set(handles.edit_zPos,'String',num2str(handles.zPosPtr.Value));
    
end

% set the relative origin equal to the current position
function handles = setZeroPosition(handles,axisStr)

    % clear the current position
    calllib('Tango_DLL','LSX_ClearPos',handles.idPtr.Value,7);

end

function handles = setPosition(handles)

    % set the absolute position
    xPos = str2double(get(handles.edit_xPos,'String'));
    yPos = str2double(get(handles.edit_yPos,'String'));
    zPos = str2double(get(handles.edit_zPos,'String'));
    
    calllib('Tango_DLL','LSX_MoveAbs',handles.idPtr.Value,xPos,yPos,zPos,0,1);

    pause(0.5);
    
end

% --- Executes on button press in pushbutton_xZero.
function pushbutton_xZero_Callback(hObject, eventdata, handles)
    % hObject    handle to pushbutton_xZero (see GCBO)
    % eventdata  reserved - to be defined in a future version of MATLAB
    % handles    structure with handles and user data (see GUIDATA)

    handles = setZeroPosition(handles,'x');
    updatePosition(handles);
    
    guidata(hObject, handles);
    
end

% --- Executes on button press in checkbox_liveUpdate.
function checkbox_liveUpdate_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox_liveUpdate (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox_liveUpdate

    if get(hObject,'Value') == 1
        % continuously update the checkbox is deactivated
        while get(handles.checkbox_liveUpdate,'Value') == 1

            updatePosition(handles);
            pause(0.5);

        end
    end

end
