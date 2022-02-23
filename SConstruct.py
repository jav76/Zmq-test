env = Environment()

Library('zmq', [])

env.Program(target='zmqTest', source=["zmqTest.c"], LIBS=["zmq"], LIBPATH = ['/usr/lib', '/usr/lib/x86_64-linux-gnu/'])