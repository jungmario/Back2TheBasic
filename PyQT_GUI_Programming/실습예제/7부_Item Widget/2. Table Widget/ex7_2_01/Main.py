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
        self.data = []

        self.btnLoad.clicked.connect(self.loadFile)
        self.btnSave.clicked.connect(self.saveFile)
        self.btnAddRow.clicked.connect(self.addRow)
        self.btnAddRow.setEnabled(False)
        self.btnSave.setEnabled(False)
        self.tableWidget.itemChanged.connect(self.func)

    def func(self, item): #문제는, 처음에 아무것도 없을 때 데이터 적을 때도 발생 -> 데이터 많아지면 개오바 -> signal 막기 필요
        r, c = item.row(), item.column()
        self.data[r+1][c] = item.text()

    def addRow(self):
        #self.tableWidget.blockSignals(True)
        #self.tableWidget.blockSignals(False) -> 위치는 다르겠지만..
        name = self.nameLineEdit.text()
        kor = self.korLineEdit.text()
        eng = self.engLineEdit.text()
        mat = self.matLineEdit.text()
        self.data.append([name, kor, eng, mat])
        self.tableWidget.setRowCount(len(self.data) - 1)
        r = self.tableWidget.rowCount() - 1
        for c, cell in enumerate(self.data[-1]):
            self.tableWidget.setItem(r, c, QTableWidgetItem(cell))
        self.tableWidget.resizeRowsToContents()

    def loadFile(self): #pandas 쓰지 않고 파이썬으로 파일 다루기
        with open('data.csv', 'r') as f:
            lines = f.readlines()
        print(lines)
        self.data = [l.rstrip().split(',') for l in lines if len(l.rstrip()) != 0] # 2중 list로 읽어오기. rstrip : 공백문자 잘라내기
        print(self.data)
        self.btnAddRow.setEnabled(True)
        self.btnSave.setEnabled(True)
        self.make_table()

    def saveFile(self):
        lines = [','.join(line) + '\n' for line in self.data]
        with open('data.csv', 'w') as f:
            f.writelines(lines)

    def make_table(self):
        self.tableWidget.setRowCount(len(self.data) - 1)
        self.tableWidget.setColumnCount(len(self.data[0]))
        hlabel = self.data[0]
        self.tableWidget.setHorizontalHeaderLabels(hlabel)

        for r, record in enumerate(self.data[1::]):
            for c, cell in enumerate(record):
                self.tableWidget.setItem(r, c, QTableWidgetItem(cell)) # 이거는 진짜 크랙이네

        self.tableWidget.resizeColumnsToContents() #이건 안배운건데
        self.tableWidget.resizeRowsToContents()


if __name__ == '__main__':
    app = QApplication(sys.argv)
    w = Form()
    w.show()
    sys.exit(app.exec_())