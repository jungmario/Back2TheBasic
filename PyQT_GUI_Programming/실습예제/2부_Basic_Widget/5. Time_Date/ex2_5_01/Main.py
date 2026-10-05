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
from PyQt5.QtCore import QTimer, QTime

class Form(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.tick = 0
        self.setupUi(self)
        # 1. 타이머 생성
        self.tmr = QTimer(self)
        # 2. 시그널 슬롯 연결 
        self.tmr.timeout.connect(self.func)
        # 3. 필요한 시점에 타이머 시작
        self.tmr.start(1000)
        self.cnt = -1

    def func(self):
        self.lcdNumber.display(QTime.currentTime().toString('HH:mm:ss'))
        self.cnt *= -1
        if self.cnt + 1:
            self.lblGreen.setStyleSheet('background-color : green')
            self.lblRed.setStyleSheet('background-color : grey')
        else:
            self.lblGreen.setStyleSheet('background-color : grey')
            self.lblRed.setStyleSheet('background-color : red')


if __name__ == '__main__':
    app = QApplication(sys.argv)
    w = Form()
    w.show()
    sys.exit(app.exec_())
