#include <gtkmm/stock.h>
#include <stdio.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <vector>
#include <gtkmm/stock.h>
#include "requeteweb.h"
#include "fenetreprincipale.h"

extern WebResponseString  web_response_string;
extern WebResponseImage   web_response_image_obj;

size_t write_callback_func(void *ptr,//buffer
                        size_t size,
                        size_t nmemb,
                        void *stream)//userp)
{
        Glib::RefPtr<Gtk::TextBuffer> m_responce_buffer1;
	m_responce_buffer1 = Gtk::TextBuffer::create();
        m_responce_buffer1->set_text(std::string(static_cast<char *>(ptr), size * nmemb));
   // std::string buf = std::string(static_cast<char *>(ptr), size * nmemb);
   // std::stringstream *response = static_cast<std::stringstream *>(stream);
   // response->write(buf.c_str(), (std::streamsize)buf.size());
       //std::cout << "requete: " << m_responce_buffer1->get_text() <<std::endl;
	//reponce_du_web=m_responce_buffer1->get_text(); 
     //  printf("The body is <%s>\n",buf.c_str()); 
	std::string dude=m_responce_buffer1->get_text();
	web_response_string.add_string_from_web(dude);
	int length= dude.size();
	    std::cout << "length " << length << std::endl;
	    std::cout << "dude " << dude << std::endl;
 // std::ofstream myfile; 
 //myfile.open ("body.out");
/*	int ie=1;
	while(ie<length){	
	 int end_line = dude.find(">\n",ie);
	 std::string line_write=dude.substr(ie,end_line-ie+3);
	 myfile << line_write;
	 ie=end_line+3;
	       std::cout << "length " << end_line  << " ::" << length <<std::endl;
	}*/
  //myfile.close();
    return size * nmemb;


//    char **response_ptr =  (char**)userp;

    /* assuming the response is a string */
  //  *response_ptr = strndup(buffer, (size_t)(size *nmemb));

}

size_t write_pdf(void *ptr,//buffer
                        size_t size,
                        size_t nmemb,
                        void *stream)//userp)
{
	//std::vector<char> vect;
	//std::vector<int>::iterator it;
	//vect.clear();
	std::string dddd=std::string(static_cast<char *>(ptr), size * nmemb);
	web_response_image_obj.add_image_from_web(dddd);
	//it = vect.begin();
	// it = vect.insert(it,dddd.c_str());
      //  Glib::RefPtr<Gtk::TextBuffer> m_responce_buffer1;
	//m_responce_buffer1 = Gtk::TextBuffer::create();
      //  m_responce_buffer1->set_text(std::string(static_cast<char *>(ptr), size * nmemb));
   // std::string buf = std::string(static_cast<char *>(ptr), size * nmemb);
   // std::stringstream *response = static_cast<std::stringstream *>(stream);
   // response->write(buf.c_str(), (std::streamsize)buf.size());
       //std::cout << "requete: " << m_responce_buffer1->get_text() <<std::endl;
	//reponce_du_web=m_responce_buffer1->get_text(); 
     //  printf("The body is <%s>\n",buf.c_str());c 

//	std::string dude=m_responce_buffer1->get_text();
//	web_response_string.add_string_from_web(dude);
//	int length= dude.size();
//	    std::cout << "length " << length << std::endl;
//	    std::cout << "dude " << dude << std::endl;
 // std::ofstream myfile; 
 //myfile.open ("body.out");
/*	int ie=1;
	while(ie<length){	
	 int end_line = dude.find(">\n",ie);
	 std::string line_write=dude.substr(ie,end_line-ie+3);
	 myfile << line_write;
	 ie=end_line+3;
	       std::cout << "length " << end_line  << " ::" << length <<std::endl;
	}*/
  //myfile.close();
    return size * nmemb;


//    char **response_ptr =  (char**)userp;

    /* assuming the response is a string */
  //  *response_ptr = strndup(buffer, (size_t)(size *nmemb));

}


size_t  write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    static int first_time=1;
    char outfilename[FILENAME_MAX] = "body.pdf";
    static FILE *outfile;
    size_t written;

	if (first_time) {
      first_time = 0;
       outfile = fopen(outfilename,"w");
       if (outfile == NULL) {
           return -1;
        }
        fprintf(stderr,"The body is <%s>\n",outfilename);
    }
    written = fwrite(ptr,size,nmemb,outfile);
	std::cout <<written<<std::endl;
//fclose(outfile);    
    return written;

}
size_t requeteweb_2(std::string requetebrut,size_t request_type,std::string *web_html_response_ptr)
{
	web_response_string.set_zero_from_web();
	web_response_image_obj.set_zero_from_web_image();
std::string requete_propre=prep_requete(requetebrut);
std::string requeteurl;
  CURL *curl;
  CURLcode res;
  char *response = NULL;

	if(request_type == 1){
	std::string url="http://ops.epo.org/2.6.2/rest-services/published-data/search?q=";
	requeteurl= url+requete_propre;
	}
	else if(request_type == 2)
	{
	requeteurl="http://ops.epo.org/2.6.2/rest-services/published-data/publication/epodoc/"+ requetebrut + "/images";
	}
	else if(request_type == 3)
	{
	//		web_response_image_obj.set_zero_from_web_image();
	requeteurl="http://ops.epo.org/2.6.2/rest-services/published-data/images/" + requetebrut+"/fullimage?range=1" ;
	}
 std::cout << "requete: " << requeteurl <<std::endl;	
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, requeteurl.c_str());
//"http://ops.epo.org/2.6.2/rest-services/published-data/search?q=applicant%3DIBM");
 
              // Tell libcurl what function to call when it has data
        if(request_type == 3) 
		{
		
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,write_pdf);
		
		}
	else if(request_type == 1|request_type == 2)	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback_func);

		/* passing the pointer to the response as the callback parameter */
	//curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);


              // Do it! 
    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curl);

    /* Check for errors */ 


    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
	printf("%d \n",res);
    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }
        if(request_type == 3) web_response_image_obj.write_pdf_file();

	//load_buffer();
  return 0;

}

size_t requeteweb(std::string requetebrut,size_t request_type)
{

std::string requete_propre=prep_requete(requetebrut);

   // char outfilename[FILENAME_MAX] = "body.out";
    //static FILE *outfile;
      // outfile = fopen(outfilename,"w");
	//fclose(outfile);
std::string requeteurl;
  CURL *curl;
  CURLcode res;
  char *response = NULL;
//std::string requetebrut;
	web_response_string.set_zero_from_web();
	web_response_image_obj.set_zero_from_web_image();
if(request_type == 1){
	
	std::string url="http://ops.epo.org/2.6.2/rest-services/published-data/search?q=";
	requeteurl= url+requete_propre;

//	int longueur=requeteurl.size();
//	const char requetechar[longueur];
//	requetechar=requeteurl.c_str();
}
else if(request_type == 2)
{
	requeteurl="http://ops.epo.org/2.6.2/rest-services/published-data/publication/epodoc/"+ requetebrut + "/images";

}
else if(request_type == 3)
{

//US country check
//int is_us = requetebrut.compare(0,2,"US")
std::cout << requetebrut.size() <<":: ::" << requetebrut.compare(0,2,"US")<<std::endl;
std::cout<<requetebrut<<std::endl;
if((requetebrut.compare(0,2,"US")==0 )){//||(requetebrut.compare(0,2,"us")==0 )){
 if((requetebrut.substr(13,1)=="/")&&(requetebrut.substr(11,1)!="B")&&(requetebrut.substr(11,1)!="A")){
	
	size_t requetebrutsize=requetebrut.size();
	requetebrut= requetebrut.substr(0,7) + "0" +requetebrut.substr(7,requetebrutsize - 7); 	
	//std::cout << inter << "allo"<<requetebrut<< std::endl;	
}
 if((requetebrut.substr(11,1)=="A")&&(requetebrut.substr(12,1)=="/")){
	
	size_t requetebrutsize=requetebrut.size();
	requetebrut= requetebrut.substr(0,12) + "1" +requetebrut.substr(12,requetebrutsize - 12); 	
	//std::cout << inter << "allo"<<requetebrut<< std::endl;	
}
}

 
//		web_response_image_obj.set_zero_from_web_image();
	requeteurl="http://ops.epo.org/2.6.2/rest-services/published-data/images/" + requetebrut;
}

 std::cout << "requete: " << requeteurl <<std::endl;	
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, requeteurl.c_str());
//"http://ops.epo.org/2.6.2/rest-services/published-data/search?q=applicant%3DIBM");
 
              // Tell libcurl what function to call when it has data
        if(request_type == 3) 
		{
		
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,write_pdf);
		
		}
	else if(request_type == 1|request_type == 2)	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback_func);

		/* passing the pointer to the response as the callback parameter */
	//curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);


              // Do it! 
    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curl);

    /* Check for errors */ 


    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
	printf("%d \n",res);
    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }
        if(request_type == 3) web_response_image_obj.write_pdf_file();

	//load_buffer();
  return 0;
}
std::string prep_requete(std::string requetebrut)
{
size_t size=requetebrut.size();
	int modifications[int (size)][1];
	int j=1;
	int i;


for (i=0;i<size;i++){

 if (requetebrut.substr(i,1) == " ")
	{
	modifications[i][1]=1;
	} 

/* else if (requetebrut.substr(i,1) == "=")
	{
	modifications[i][1]=2;
	} */
/* else if (requetebrut.substr(i,1) == "&")
	{
	modifications[i][1]=3;
	}*/ 
 else
	{
	modifications[i][1]=0;
	}
 //std::cout << "letter: " << requetebrut.substr(i,1) <<std::endl;	

}
i=0;
j=0;
while (i<size)
{
	if (modifications[j][1]==1)
	{
	requetebrut.erase(i,1);
	requetebrut.insert(i,"%20");
	size=size+2;
	i=i+2;
	}
	else if (modifications[j][1]==2)
	{
	requetebrut.erase(i,1);
	requetebrut.insert(i,"%3D");
	size=size +2;
	i=i+2;
	} 
	else if (modifications[j][1]==3)
	{
	requetebrut.erase(i,1);
	requetebrut.insert(i,"%26");
	size=size +2;
	i=i+2;
	}
	i++;
	j++;
}


return requetebrut;

}
void WebResponseString::set_zero_from_web()
{
web_response="";
std::cout << "web_response zero : " << web_response<<std::endl;
}
void WebResponseString::add_string_from_web(std::string string)
{
web_response=web_response + string;
//std::cout << "web_response add: " << web_response<<std::endl;
}
void WebResponseString::set_string_from_web(std::string string)
{
web_response=string;
//std::cout << "web_response set: " << web_response<<std::endl;
}
std::string WebResponseString::get_string_from_web()
{
return web_response;
}
WebResponseString::WebResponseString()
{
}

WebResponseString::~WebResponseString()
{
}
void load_buffer()
{
//web_response_string="";
std::string string;
  std::ifstream myfile ("body.out");
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      std::getline (myfile,string);
      std::cout << string << std::endl;
    }
    myfile.close();
  }

  else std::cout << "Unable to open file"; 

web_response_string.set_string_from_web(string);

}
WebResponseImage::WebResponseImage()
{
}

WebResponseImage::~WebResponseImage()
{
}
void WebResponseImage::set_image_from_web(std::string string)
{
web_response_image=string;
}
void WebResponseImage::add_image_from_web(std::string string)
{
web_response_image=web_response_image + string;
}
std::string WebResponseImage::get_image_from_web()
{
return web_response_image;
}
void WebResponseImage::set_zero_from_web_image()
{
web_response_image="";
}
void WebResponseImage::write_pdf_file()
{
 std::ofstream myfile; 
myfile.open ("body.pdf");

myfile << web_response_image;

myfile.close();

}
