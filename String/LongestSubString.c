int lengthOfLongestSubstring(char* s) {
    int last_index[256];
    for(int i=0;i<256;i++){
        last_index[i]=-1;
    }
    int max_length=0;
    int start=0;
    for(int i=0;s[i]!='\0';i++){
        unsigned char ch=s[i];
        if(last_index[ch]>=start){
            start=last_index[ch]+1;
        }
        last_index[ch]=i;
        int currentlen=i-start+1;
        if(currentlen>max_length){
            max_length=currentlen;
        }
    }
    return max_length;
}