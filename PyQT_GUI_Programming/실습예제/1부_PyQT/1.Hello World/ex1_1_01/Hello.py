# import sys
# from PyQt5.QtWidgets import *

# if __name__ == '__main__':

#     app = QApplication(sys.argv)

#     w = QWidget()
#     w.setGeometry(100,100,200,50)
#     w.setWindowTitle('PyQT')

#     label = QLabel(w)
#     label.setText("Hello World")
#     label.move(50,20)
#     w.show()

#     app.exec_()

def func(f):
    return f(3,4) #이게 콜백함수, 대신 실행해줌 sort의 key = 에 넣어주는 함수. '함수(이름)'만 넘겨주면 내가 호출해서 출력해줄게. 함수() 이러면 return값이 넘어감. 함수 만들기 귀찮으면 lambda 넘기겠지.

def add(a, b):
    return a + b

def sub(a, b):
    return a - b

def mul(a, b):
    return (a * b)

r = func(add)

print(r) 