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
        self.idpass = { 'AXQ1000' : '123456', 'AXQ1001' : '123456', 'AXQ1002' : '123456', 'AXQ1003' : '123456', 'AXQ1004' : '123456'}
        self.btnOK.clicked.connect(self.Ok_chk)
        self.btnChange.clicked.connect(self.Ps_chg)

    def Ok_chk(self):
        if not self.Check_Validation(): return
        elif self.linID.text() not in self.idpass:
            QMessageBox.warning(self, '오류', '존재하지 않는 아이디입니다.')
        elif self.linPass.text() != self.idpass[self.linID.text()]:
            QMessageBox.warning(self,'오류', '비밀번호가 틀렸습니다')
        else : 
            QMessageBox.information(self, '성공', '인증되었습니다')

    def Ps_chg(self):
         if not self.Check_Validation(): return

         else:
            r = QMessageBox.question(self, '변경', '비밀번호를 변경하시겠습니까?', QMessageBox.Yes | QMessageBox.No)
            if r == QMessageBox.Yes:
                self.idpass[self.linID.text()] = self.linPass.text()
                QMessageBox.information(self, '비밀번호 변경', f'비밀번호 변경 : [{self.linPass.text()}]')
                
    def Check_Validation(self):
        for wid in self.findChildren(QLineEdit):
            if not wid.hasAcceptableInput():
                item = self.formLayout.labelForField(wid).text()
                QMessageBox.critical(self, f'{item} 오류', f'{item}를 입력해 주세요')
                return False
        return True


if __name__ == '__main__':
    app = QApplication(sys.argv)
    w = Form()
    w.show()
    sys.exit(app.exec_())
