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

        self.actionNew.triggered.connect(self.New_trig)
        self.actionOpen.triggered.connect(self.Open_trig)
        self.actionSave.triggered.connect(self.Save_trig)


    def New_trig(self):
        print('New')
    def Open_trig(self):
        print('Open')
    def Save_trig(self):
        print('Save')

if __name__ == '__main__':
    app = QApplication(sys.argv)
    w = Form()
    w.show()
    sys.exit(app.exec_())
