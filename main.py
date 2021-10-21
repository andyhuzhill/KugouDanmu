#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys

import json

from PyQt5.QtCore import QObject, pyqtSignal, pyqtSlot
from PyQt5.QtGui import QGuiApplication, QFont
from PyQt5.QtQml import QQmlApplicationEngine

import qml

import asyncio
import danmaku

from threading import Thread

running = True

class KugouProto(QObject):
    newMessage = pyqtSignal(str, str)

    def __init__(self) -> None:
        super().__init__()

    def onNewMessage(self, name, message):
        self.newMessage.emit(name, message)
    
    
async def printer(q, kugou):
    global running
    while running:
        m = await q.get()
        if m['msg_type'] == 'danmaku':
            print(f'{m["name"]}：{m["content"]}')
            kugou.onNewMessage(m["name"], m["content"])


async def main(url, kugou):
    q = asyncio.Queue()
    dmc = danmaku.DanmakuClient(url, q)
    asyncio.create_task(printer(q, kugou))
    await dmc.start()


def runDmk(kugou):
    asyncio.run(main("https://fanxing.kugou.com/5210604", kugou))


def guiMain():
    app = QGuiApplication(sys.argv)
    font = QFont("Microsoft YaHei")
    app.setFont(font)
    
    engine = QQmlApplicationEngine()
    rootContext = engine.rootContext()

    kugou = KugouProto()
    rootContext.setContextProperty("kugou", kugou)

    engine.load("qrc:/main.qml")

    t = Thread(target = runDmk, args=(kugou,))
    t.start()

    sys.exit(app.exec_())

    running = False

    t.join()

if __name__ == "__main__":
    guiMain()
