
#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

int main (void)
{
    //  Socket to talk to clients
    void *context = zmq_ctx_new ();
    void *responder = zmq_socket (context, ZMQ_PULL);
    int rc = zmq_bind (responder, "tcp://*:5555");
    assert (rc == 0);

    while (1) {
        char buffer [10];
        zmq_recv (responder, buffer, 10, 0);
        if (strlen(buffer) > 0)
        {
            printf ("Received %s\n", buffer);
        }
        sleep (1);          //  Do some 'work'
        strcpy(buffer, "");
        
    }
    return 0;
}
