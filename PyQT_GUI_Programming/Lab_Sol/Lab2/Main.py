import sys, subprocess
from PyQt5.QtWidgets import *

GUI_FILE_NAME = 'ui'
subprocess.run([
    sys.executable,          
    '-m', 'PyQt5.uic.pyuic', 
    '-x', f'{GUI_FILE_NAME}.ui', 
    '-o', f'{GUI_FILE_NAME}.py'
])
from ui import Ui_MainWindow


class Form(QMainWindow, Ui_MainWindow):

    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.btnGroupDisp.buttonClicked.connect(self.Disp)
        self.btnGroupOp.buttonClicked.connect(self.Op)
        self.str = ''

    def Disp(self, s):
        self.str += s.text()
        self.lblDisp.setText(self.str)

    def Op(self, op):
        btn_text = op.text()

        if btn_text == '←': 
            self.str = self.str[:-1]
        elif btn_text == 'C': 
            self.str = ''
        elif btn_text == '=': 
            calc_str = self.str.replace('×', '*').replace('÷', '/')
            try:
                self.str = f'{eval(calc_str)}'
                self.lblDisp.setText(self.str)
            except ZeroDivisionError:
                self.lblDisp.setText("0으로 나눌 수 없습니다")
                self.str = ''
            except SyntaxError:
                self.lblDisp.setText("잘못된 수식 입니다")
                self.str = ''
            except Exception as e:
                self.lblDisp.setText("오류")
                self.str = ''
            
            return

        self.lblDisp.setText(self.str)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    w = Form()
    w.show()
    sys.exit(app.exec_())
