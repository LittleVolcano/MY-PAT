#include <iostream>
#include <cstring>
const int maxn = 1100;
struct bign{
	int d[maxn];
	int len;
	bign(){
		memset(d, 0, sizeof(d));		
		len = 0;
	}
};
bign change(char str[]){//�����ַ���Ҫ�������ţ�����ͳ�����Ԫ��ָ���� 
	bign a;
	a.len = strlen(str);
	for(int i = 0;i < a.len;i++){
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a;
}
bool isPalindromic(bign a){
	int i = 0,j = a.len - 1;
	while(i < j){
		if(a.d[i] != a.d[j]){
			return false;	
		}
		++i;
		--j;
	}
	return true;
}
bign add(bign a,bign b){
	bign c;
	int carry = 0;
	for(int i = 0;i < a.len || i < b.len; i++){
		int temp = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = temp % 10;
		carry = temp / 10;
	}
	if(carry != 0){
		c.d[c.len++] = carry;
	}
	return c;
}
bign reverse(bign a){
	bign b;
	for(int i = a.len - 1;i >= 0; i--){
		b.d[b.len++] = a.d[i];
	}
	return b;
}
void print(bign a){
	for(int i = a.len - 1;i >= 0; i--){
		printf("%d",a.d[i]);
	}
}
int main(int argc, char** argv) {
	char str[maxn];
	scanf("%s",str);
	bign a = change(str), b, c;
	bool flag = false;
	if(isPalindromic(a)){//���������ֵ��Ҫ�����ǲ��Ƿ��������������ǵĻ���Ӧ����ӷ�ʽ��Ӧ��������� 
		print(a);
		printf(" is a palindromic number.");
		flag = true;
	}
	int T = 10;
	while(T-- && flag == false){
		b = reverse(a);
		c = add(a, b);
		print(a);
		printf(" + ");
		print(b);
		printf(" = ");
		print(c);
		printf("\n");		
		if(isPalindromic(c)){
			print(c);
			printf(" is a palindromic number.");
			flag = true;
			break;
		}
		a = c;
	}
	if(flag == false){
		printf("Not found in 10 iterations.");
	}
	return 0;
}

//
//Ĥ�����SС��� 
//#include <iostream>
//#include <algorithm>
//using namespace std;
//string add(string a) {
//    string b = a, ans; 							//�ַ�������ֱ�ӻ��ำֵ 
//    reverse(b.begin(), b.end());					//algorithm������ô���õĶ��� 
//    int len = a.length(), carry = 0;
//    for (int i = 0; i < len; i++) {
//        int num = (a[i] - '0' + b[i] - '0') + carry;
//        carry = 0;
//        if (num >= 10) {
//            carry = 1;
//            num = num - 10;
//        }
//        ans += char(num + '0');
//    }
//    if(carry == 1) ans += '1';
//    reverse(ans.begin(), ans.end());
//    return ans;
//}
//int main() {
//    string s;
//    cin >> s;
//    int cnt = 0;
//    while (cnt < 10) {
//        string t = s;
//        reverse(t.begin(), t.end());
//        if (t == s) {						//�ַ�������ֱ�ӱȽϣ������� 
//            cout << s << " is a palindromic number.";
//            break;
//        } else {
//            cout << s << " + " << t << " = " << add(s) << endl;
//            s = add(s);
//            cnt++;
//        }
//    }
//    if (cnt == 10) cout << "Not found in 10 iterations.";
//    return 0;
//}
