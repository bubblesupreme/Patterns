
package HTTPServer;

import Request.HttpRequest;
import Response.HttpResponse;
import java.net.ServerSocket;
import java.net.Socket;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;


public class HttpServer {

    private static Router router;
    
    public HttpServer()
    {
        router = new Router();
        router.add_route("/first", new FirstController());
        router.add_route("/second", new SecondController());   
    }
    
    public static void main(String[] args) throws Throwable {
        HttpServer http_server = new HttpServer();
        ServerSocket ss = new ServerSocket(8080);
        while (true) {
            Socket s = ss.accept();
            System.err.println("Client accepted");
            new Thread(new SocketProcessor(s)).start();
        }    
    }
private static class SocketProcessor implements Runnable {

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
                IController controller = 
                        new LoggingControllerWrapper(
                                router.choiceController(
                                        http_request.getRequestLine().getUrl()));
                switch (http_request.getRequestLine().getAction())
                {
                    case "GET":
                        writeResponse(controller.get(http_request));
                        break;
                    case "POST":
                        writeResponse(controller.post(http_request));
                        break;
                    default:
                        break;
                }
//               
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
            String str= response.toString();
            System.out.print(str);
            os.write(str.getBytes());
            os.flush();
        }

        private HttpRequest readInputHeaders() throws Throwable {
            return new HttpRequest(new BufferedReader(new InputStreamReader(is)));
        }
    }
}
