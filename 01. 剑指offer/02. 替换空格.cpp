// 请实现一个函数，将一个字符串中的每个空格替换成'%20'
// 例如，当字符串为 We Are Happy 则经过替换之后的字符串为 We%20Are%20Happy 

class Solution {
public:
	void replaceSpace(char *str,int length) {
        int i, j, len;
        
        for(i=len=0; i<length; ++i) 
            if(str[i] == ' ') ++len;
        len = len*2+length;
        str[len] = '\0';
        for(i=length-1, j=len-1; i>=0; --i) {
            if(str[i] != ' ') str[j--] = str[i];
            else { str[j--] = '0'; str[j--] = '2'; str[j--] = '%'; }
        }
	}
};
