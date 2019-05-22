
package HTTPServer;

public class Main {
        public static void main(String[] args) {
            try{
                Router router = new Router();
                router.addRoute("/first", new LoggingControllerWrapper(new FirstController()));
                router.addRoute("/second", new LoggingControllerWrapper(new SecondController()));
                HttpServer httpServer = new HttpServer(router);  
                httpServer.listen();
            }
            catch (Throwable t)
            {
                System.out.print(t);
            } 
    }
}
