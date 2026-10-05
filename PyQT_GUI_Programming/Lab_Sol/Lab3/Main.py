import sys, subprocess
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

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
        self.btnOpen.clicked.connect(self.Open_file)

    def Open_file(self):
        showfilter = '비트맵 파일(*.bmp);;JPEG (*.jpg;*.jpeg);;GIF (*.gif);;PNG (*.png);;ICO(*.ICO)'
        initfilter = 'JPEG (*.jpg;*.jpeg)'
        filepath, filtertype = QFileDialog.getOpenFileName(filter=showfilter, initialFilter=initfilter)

        pixmap = QPixmap(filepath)
        self.lblImage.setPixmap(pixmap)
        self.lblImage.resize(pixmap.size())


if __name__ == '__main__':
    app = QApplication(sys.argv)
    w = Form()
    w.show()
    sys.exit(app.exec_())
