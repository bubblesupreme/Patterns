
package HTTPServer;

import Request.HttpRequest;
import Response.HttpResponse;
import java.net.ServerSocket;
import java.net.Socket;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;


public class HttpServer {

    private Router router;
    
    public HttpServer(Router router)
    {
        this.router=router;
    }
    
    public void listen() throws IOException, Throwable
    {
        ServerSocket ss = new ServerSocket(8080);
        while (true) {
            Socket s = ss.accept();
            System.err.println("Client accepted");
            new Thread(new SocketProcessor(s)).start();
        }  
    }
    
private class SocketProcessor implements Runnable {

        private Socket s;
        private InputStream is;
        private OutputStream os;

        private SocketProcessor(Socket s) throws Throwable {
            this.s = s;
            this.is = s.getInputStream();
            this.os = s.getOutputStream();
        }

        @Override
        public void run() {
            try {
                HttpRequest http_request=readInputHeaders();
                switch (http_request.getRequestLine().getAction())
                {
                    case "GET":
                        writeResponse(router.chooseController(http_request.getRequestLine().getUrl()).get(http_request));
                        break;
                    case "POST":
                        writeResponse(router.chooseController(http_request.getRequestLine().getUrl()).post(http_request));
                        break;
                    default:
                        break;
                }               
            } catch (Throwable t) {
            } finally {
                try {
                    s.close();
                } catch (Throwable t) {
                }
            }
            System.err.println("Client processing finished");
        }
         private void writeResponse(HttpResponse response) throws Throwable {
            os.write(response.getResponse().getBytes());
            os.flush();
        }

        private HttpRequest readInputHeaders() throws Throwable {
            return new HttpRequest(new BufferedReader(new InputStreamReader(is)));
        }
    }
}
