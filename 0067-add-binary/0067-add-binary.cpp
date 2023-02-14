class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        char p1,p2;
        string c="";
        int carry = 0,i=0,j=0;
        for (i = 0,j =0;i<(int)(a.length())&&j<(int)(b.length());i++,j++){
            p1 = a[i];
            p2 = b[j];
            p2 = p1+p2-'0'-'0'+carry;
            carry = p2/2;
            if(p2%2) c+='1';
            else c+='0'; 
        }
        while(i<(int)(a.length())){
            p1 = a[i]-'0'+carry;
            carry = p1/2;
            if(p1%2) c+= '1';
            else c+='0';
            i++;
        }
        while(j<(int)(b.length())){
            p2 = b[j]-'0'+carry;
            carry = p2/2;
            if(p2%2) c+= '1';
            else c+='0';
            j++;
        }
        if(carry) c+='1';
        reverse(c.begin(),c.end());
        cout<<c<<endl;
        return c;
    }
};