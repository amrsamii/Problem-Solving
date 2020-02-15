#include <bits/stdc++.h>

typedef long long ll;
using namespace std;



int main() {

    string s;
    cin>>s;
    if(s[0] != '9' && s[0] > '4')
        s[0] = '9' - s[0] + '0';
    for(int i=1;i<s.length();i++){

        if((s[i] > '4' )){
            s[i] = '9' - s[i] + '0';
        }
    }

    cout<<s;
    return 0;
}



عشان اشوف كل digit واشوف اطرح ولا لا لازم اخد الرقم فى string وهو عشان رقم اخر 10^18 معنى كدا ان اخره 18 digit فدا هيجى فى string واقدر اعمل loop عليه انما لو كان 10^18 digit يبقى دا مستحيل يخلص فخلى بالك من الفرق بينهم لو رقم long long يبقى اقدر ا loop على ال digits بتوعه

فى حاجة مهمة هى ال leading zero ان لو اول رقم كان 9 وطرحت منه 9 هيبقى leading zero فلازم اتاكد ان اول digit مش 9 وفى نفس الوقت يكون اكبر من 4 يعنى من اول 5 ساعتها اقدر اعمل flip لاول digit

بعد كدا هعمل loop من اول digit لحد الاخر وبشوف لو اكبر من 4 يبقى ساعتها اعمله flip 

بزود 0 بعد ما اطرح عشان الطرح هيطلع رقم مش ascii فبضيف 0 ك ascii عشان لما اطبع يطلع صح
