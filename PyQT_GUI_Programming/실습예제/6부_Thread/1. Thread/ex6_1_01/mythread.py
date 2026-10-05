from PyQt5.QtCore import QThread, pyqtSignal

class MyThread(QThread):
    send_command = pyqtSignal(int)

    def __init__(self):
        super().__init__()
        send_command = pyqtSignal(int)
        self.running = False # 구동 중인지 아닌지
    # 다음 메서드를 작성하라
    def run(self): #Overide 시키기, 일을 해주는 애
        cnt = 0
        self.running = True
        while self.running:
            self.msleep(100) #아무것도 안하고 1초
            if cnt == 10:
                cnt = 0
                self.send_command.emit(1)
            cnt += 1

    # 다음 메서드를 작성하라
    def stop(self):
        self.running = False
    # 다음 메서드를 작성하라
    def is_running(self):
        return self.running