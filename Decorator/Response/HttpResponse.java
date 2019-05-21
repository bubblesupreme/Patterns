
package Response;

import java.io.InputStream;
import java.util.Scanner;

public class HttpResponse {
    private ResponseLine res_line;
    private ResponseHeaders res_headers;
    private InputStream body;
    
    public HttpResponse(ResponseLine res_line, ResponseHeaders res_headers, 
            InputStream body)
    {
        this.res_line=res_line;
        this.res_headers=res_headers;
        this.body=body;
    }
    
    @Override
    public String toString()
    {
        StringBuilder ret_str=new StringBuilder();
        ret_str.append(res_line).append("\r\n");
        ret_str.append(res_headers).append("\r\n");
        ret_str.append(StreamToString(body));
        return ret_str.toString();
    }
    
    private String StreamToString(InputStream stream)
    {
        Scanner sc= new Scanner(stream).useDelimiter("\\A");
        return sc.hasNext() ? sc.next():"";
    }
}