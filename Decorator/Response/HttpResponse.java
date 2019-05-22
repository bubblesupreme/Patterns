
package Response;

import static Utils.ConvertStreamToString.StreamToString;
import java.io.ByteArrayInputStream;
import java.io.InputStream;

public class HttpResponse {
    private ResponseLine resLine;
    private ResponseHeaders resHeaders;
    private InputStream body;
    
    public HttpResponse(ResponseLine resLine, ResponseHeaders resHeaders, 
            InputStream body)
    {
        this.resLine=resLine;
        this.resHeaders=resHeaders;
        this.body=body;
    }
    
    public static HttpResponse NotFoundResponse() 
    {
        return new HttpResponse(new ResponseLine("HTTP/1.1", 404, "Not Found"), 
                new ResponseHeaders(),
                new ByteArrayInputStream("404: Resource Not Found".getBytes()));
    }
    
    public static HttpResponse OKResponse(ResponseHeaders res_headers, InputStream body) 
    {
        return new HttpResponse(new ResponseLine("HTTP/1.1", 200, "OK"), res_headers, body);
    }
    
    public String getResponse()
    {
        StringBuilder ret_str=new StringBuilder();
        ret_str.append(resLine).append("\r\n");
        ret_str.append(resHeaders).append("\r\n");
        ret_str.append(StreamToString(body));
        return ret_str.toString();
    }
    
    public ResponseLine getResponseLine()
    {
        return resLine;
    }
    
    public ResponseHeaders getResponseHeaders()
    {
        return resHeaders;
    }
    
    public String getBody()
    {
        return StreamToString(body);
    }
}