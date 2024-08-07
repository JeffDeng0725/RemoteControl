from pywinauto import Application

# 启动应用程序
app = Application(backend="uia").start(r"C:\path\to\your\exe\file.exe")

# 连接到应用程序窗口
dlg = app.window(title_re="Tango C# Trigger Example 1")

# 设置 Meander 参数
def set_meander_parameters(x_value, y_value):
    dlg.child_window(auto_id="XInputField").set_edit_text(str(x_value))  # 根据自动ID或控件属性修改
    dlg.child_window(auto_id="YInputField").set_edit_text(str(y_value))  # 根据自动ID或控件属性修改

# 示例：设置 X 和 Y 为新的值
set_meander_parameters(20, 5)
