#include<bits/stdc++.h>
using namespace std;

void validate(string s)
{
    int l=s.length();
    /* Checking if password length is less than 6*/
    if(l < 6)
    {
        cout<<s<<" Failure Password must be at least 6 characters long.";
        return;
    }
    /* Checking if password length is greater than 12*/
    else if(l > 12)
    {
        cout<<s<<" Failure Password must be at max 12 characters long.";
        return;
    }
    else
    {
        int lower_case=0, upper_case=0, number=0, special_character=0;
        bool flag=false;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]>='a' && s[i]<='z') lower_case++;
            else if(s[i]>='A' && s[i]<='Z') upper_case++;
            else if(s[i]>='0' && s[i]<='9') number++;
            else if(s[i]=='*' || s[i]=='$' || s[i]=='_' || s[i]=='#' || s[i]=='=' || s[i]=='@') special_character++;
            else if(s[i]=='%' || s[i]=='!' || s[i]=='(' || s[i]==')')
            {
                flag=true;
                break;
            }
        }

        if(flag)
        {
            cout<<s<<" Password cannot contain %!)(.";
            return;
        }

        /* Check for a valid password */
        if(lower_case >0 && upper_case>0 && number>0 && special_character>0)
        {
            cout<<s<<" Success";
            return;
        }
        /*Checking for which case password is invalid*/
        else
        {
            if(lower_case==0) cout<<s<<" Password must contain at least one letter from a-z.";
            else if(upper_case==0) cout<<s<<" Password must contain at least one letter from A-Z.";
            else if(number==0) cout<<s<<" Password must contain at least one letter from 0-9.";
            else cout<<s<<" Password must contain at least one letter from *$_#=@.";
            return;
        }
    }
}

int main()
{
    string input;
    getline(cin,input);

    string s="";
    for(int i=0; i<input.length(); i++)
    {
        if(input[i]==',' || i==input.length()-1)
        {
            if(s.length()>0)
            {
                /* Seaparating password over commas, and then checking for validity*/
                validate(s);
                cout<<endl;
                s="";
            }
        }
        else s+=input[i];
    }
}
