import sys, subprocess
from PyQt5.QtWidgets import *

GUI_FILE_NAME = 'gui'
subprocess.run([
    sys.executable,          
    '-m', 'PyQt5.uic.pyuic', 
    '-x', f'{GUI_FILE_NAME}.ui', 
    '-o', f'{GUI_FILE_NAME}.py'
])
from gui import Ui_MainWindow


class Form(QMainWindow, Ui_MainWindow):

    def __init__(self):
        super().__init__()
        self.setupUi(self)

        self.count = 0
        self.ls = ['red', 'green', 'blue']
        self.lblState.setStyleSheet('background-color: red')

        self.btnPush.clicked.connect(self.Change_Color)
        self.btnToggle.toggled.connect(self.set_state)
        

    def Change_Color(self):
        self.lblColor.setStyleSheet(f'background-color: {self.ls[self.count % 3]}')
        self.count += 1

    def set_state(self, arg):
        if arg == True:
            self.lblState.setStyleSheet('background-color: green') #if else문 쓰면 됐잖아!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 'green' if arg == True else 'red'
        else:
            self.lblState.setStyleSheet('background-color: red')



    #self.lblState.setStyleSheet('background-color: red')


if __name__ == '__main__':
    app = QApplication(sys.argv)
    w = Form()
    w.show()
    sys.exit(app.exec_())
