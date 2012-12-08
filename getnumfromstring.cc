#include <string>
#include <stdio.h>
#include <math.h>
#include "getnumfromstring.h"

int get_number_from_string_out(std::string num_result_text)
{
size_t length_result=num_result_text.size();
int num_result = 0;
 for(size_t i=0;i<length_result;i++)
{
	
	if (num_result_text.compare(i,1,"1") == 0)
	{
		num_result=num_result*10+1;
	}
	else if (num_result_text.compare(i,1,"2") == 0)
	{
		num_result=num_result*10+2;
	}
	else if (num_result_text.compare(i,1,"3") == 0)
	{
		num_result=num_result*10+3;
	}
	else if (num_result_text.compare(i,1,"4") == 0)
	{
		num_result=num_result*10+4;
	}
	else if (num_result_text.compare(i,1,"5") == 0)
	{
		num_result=num_result*10+5;
	}
	else if (num_result_text.compare(i,1,"6") == 0)
	{
		num_result=num_result*10+6;
	}
	else if (num_result_text.compare(i,1,"7") == 0)
	{
		num_result=num_result*10+7;
	}
	else if (num_result_text.compare(i,1,"8") == 0)
	{
		num_result=num_result*10+8;
	}
	else if (num_result_text.compare(i,1,"9") == 0)
	{
		num_result=num_result*10+9;
	}
	else if (num_result_text.compare(i,1,"0") == 0)
	{
		num_result=num_result*10+0;
	}
}
//std::cout << "text: "<< num_result_text<< " length: " <<length_result << " number: " <<num_result << std::endl;
return num_result;
}

