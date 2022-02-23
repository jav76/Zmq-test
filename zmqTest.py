import zmq, time

context = zmq.Context()

#  Socket to talk to server
print("Connecting to hello world server...")
socket = context.socket(zmq.PUSH)
socket.connect("tcp://localhost:5555")

#  Send 10 messages to the server
for request in range(10):
    print(f"Sending request {request} ...")
    socket.send_string(f"Hello{request}\0")

    time.sleep(2)