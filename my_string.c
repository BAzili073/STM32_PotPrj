#include "defines.h"
#include INCLUDED_FILE_1
#include INCLUDED_FILE_2
#include "my_string.h"

int find_str(char * find,char * string){
	int counter = 0;
	int find_length = str_length(find);
	int string_length = str_length(string);
	while(counter <= (string_length - find_length)){
			if (find[0] == string[counter]){
				int u;
				unsigned int coincidence = 0;
				for (u = 0;u<find_length;u++){
					if (find[u] == string[counter + u]){
						coincidence++;
						if (coincidence == find_length) return 1;
					}else{
							coincidence = 0;
							break;
					}
				}
		}
		counter++;
	}
	return 0;
}

unsigned int str_length(char * str){
	unsigned int i = 0;
	while(str[i] != '\0'){
		i++;
	}
	return i;
}

void str_add_str ( char * in,int size_in,char * out,unsigned int len){
	unsigned int i = 0;
	unsigned int in_len = str_length(in);
	unsigned int out_len = str_length(out);
	if ((out_len > len) && (len)) out_len = len;
//	in_len ? in_len++ : 0;
	for (i = 0;i<out_len;i++){
		if ((in_len+i) >= size_in) return;
		in[in_len+i] = out[i];
	}
}

void str_add_num(char * out,int num){
	int i = 5;
	int y;
	int out_len = str_length(out);
	if (num < 0) {
		num = num * (-1);
		out[out_len] = '-';
		out_len++;
	}
	for (i = 9;i>=0;i--){
		int a = num;
		for (y = i;y>0;y--) a = a/10;
		if (a || !i){
			out[out_len] = (48 + a);
			out_len++;
			for (y = i;y>0;y--) a = a*10;
			num = num-a;
			if (!num && i) {
				for (y=0;y<i;y++){
					out[out_len] = '0';
					out_len++;
				}
				return;
			}
		}
	}
}

uint8_t get_size_number(int32_t num){
	int mult = 0;
	if (num < 0) {
		mult = 1;
		num = num * (-1);
	}
	if (num >= 100000) return (mult + 6);
	if (num >= 10000) return (mult + 5);
	if (num >= 1000) return (mult + 4);
	if (num >= 100) return (mult + 3);
	if (num >= 10) return (mult + 2);
	return (mult + 1);
}
