from flask import Flask
import serial
import socket
app = Flask(__name__)


@app.route('/')
def hello_world():
    ser = serial.Serial('/dev/ttyACM0', 115200)
    return ser.readline()


if __name__ == '__main__':
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.connect(('8.8.8.8', 0))
    ipAddress = s.getsockname()[0]
    app.run(host=ipAddress, port=5000)
