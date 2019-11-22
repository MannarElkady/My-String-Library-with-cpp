#include<stdio.h>
#include<iostream.h>
#include<conio.h>

class String{
	private:
		int size,length;
		char *str;
	public:
		String(char*txt);  //done
		String(String&s);  //done
		~String();        //done
		String concat(String &s);     //done
		String operator+(String &s);  //done
		String& operator+=(String&s); //done
		String &operator=(String&s);  //done
		String &operator=(char*s);    //done
		int indexOf(char ch);             //done
		int indexOf(char ch,int offset);  //done
		char charAt(int index);           //done
		int stringLength();               //done
		int equals(String &s);            //done
		int equals(char *s);              //done
		int equalsIgnore(char*s);         //done
		int equalsIgnore(String&s);       //done
		String replaceText(String &s,int start,int end); //done
		String insertText(String&s,int start);//done
		String subString(int start);          //done
		String subString(int start,int end);  //done
		static String upperCase(String &s);   //done
		void printString();                   //done
		static String lowerCase(String &s);   //done
};

String::String(char * txt){
	length=0;size=0;
	int i=0;
	while(*(txt+i)!='\0')
	{
		length++;
		i++;
	}
	size=length+1;
	str=new char[size];
	for(i=0;i<size;i++)
	{
		str[i]=txt[i];
	}
	str[size]='\0';
//	cout<<"\nstring : "<<str;
}
char String::charAt(int index)
{
	if(index<length)
		return str[index];
	return -1;
}
String::String(String &s)
{
	size=s.size;
	length=s.length;
	str=new char[length];
//	cout<<"\nString Constructor";
	for(int i=0;i<s.length;i++)
	{
		str[i]=s.str[i];
	}
	str[length]='/0';

}

String::~String()
{
	delete[]str;
}


int String::stringLength(){
	return this->length;
}


int String::indexOf(char ch){
	for(int i=0;i<length;i++)
	{
		if(str[i]==ch)
			return i;
	}
	return -1;

}

int String::indexOf(char ch,int offset){
	for(int i=offset;i<length;i++)
	{
		if(str[i]==ch)
			return i;
	}
	return -1;

}


String String::subString(int start,int end)
{
	//this function substring from the start till the end
	//and stops after end
	char* temp;
	if(end>this->length)
	{
		end=this->length;
	}
	int temp_length=end-start+1;
	temp=new char[temp_length];
	for(int i=0;i<temp_length;i++)
	{
		temp[i]=str[i+start];
		if(i>end)
			break;
	}
	temp[temp_length]='\0';
	String s(temp);
	delete[]temp;
	return s;
}

String String::subString(int start)
{
	return subString(start,this->length);
}
String String::concat(String&s){
	int temp_length;
	char* temp;
	temp_length=length+s.length;
	temp=new char[temp_length];
	for(int i=0;i<length;i++)
	{
		temp[i]=str[i];
		cout<<temp[i];
	}
	for(i=0;i<s.length;i++)
	{
		temp[i+length]= s.str[i];
		//cout<<temp[i+length];

	}
	temp[length+s.length]='\0';
   //cout<<"\nBefore concatination: "<<str<<"\nAfter Concatination String: "<<temp;
	String s2(temp);
	delete[]temp;
	return s2;
}

String & String::operator=(String&s){
	length=s.length;
	size=s.size;
	delete []str;
	str=new char[s.size];
	for(int i=0;i<s.length;i++)
	{
		str[i]=s.str[i];
	}
	str[length]='\0';
	return (* this);
}



String& String::operator=(char*s)
{
	String temp(s);
	cout<<"\n before assignment with = to chars "<< str;
	*this=temp;
	cout<<"\n after assignment with = to chars "<< str;
	return (* this);
}


String &String::operator+=(String&s)
{
	if((size-length-1)>=s.length)
	{
		for(int i=0;i<s.length;i++)
		{
			s.str[length+i]=s.str[i];
		};
	}

	else{
		char * temp;
		temp=new char[length+s.length+1];
		for(int i=0;i<length;i++)
		{
			temp[i]=str[i];
		}
		for(i=0;i<s.length;i++)
		{
			temp[i+length]=s.str[i];
		}
		size+=s.size;
		length+=s.length;
		temp[length]='\0';
		delete[]str;
		str=temp;
		temp=NULL;

	}
	str[length+1]='\0';
//	cout<<endl<<"\nstring from+= is  "<<str;
	return (* this);
}

String String::operator+(String&s){
	return(this->concat(s));
}

int String::equals(String &s){

	if(length!=s.length)
	{
		return 0;
	}

	for(int i=0;i<s.length;i++)
	{
		if(str[i]!=s.str[i])
		{
				return 0;
		}
	}
	return 1;

}

int String::equals(char *s){

	int bool;
	String temp(s);
	bool=this->equals(temp);
	return bool;

}

String String::upperCase(String &s)
{
	char *temp;
	temp=new char[s.size];
	for(int i=0;i<s.length;i++)
	{
		if(s.str[i]>=97 && s.str[i]<=122)
		{
			temp[i]=s.str[i]-32;
		}
		else
		{
			temp[i]=s.str[i];
		}

	}
	temp[s.length]='\0';
   //	cout<<"\nUppercase for the string  "<<s.str<<"  is:  "<<temp<<endl;
	String s2(temp);
	delete[]temp;
	return s2;

}

void String::printString()
{
	cout<<"\nString: ";
	for(int i=0;i<length;i++)
	{
		cout<<str[i];
	}
	cout<<"  with length: "<<this->length<<endl;
   //	cout<<"\nString: "<< this->str<<" with length: "<<this->length<<endl;
}

String String::lowerCase(String &s)
{
	char *temp;
	temp=new char[s.size];
	for(int i=0;i<s.length;i++)
	{
		if(s.str[i]>=65 && s.str[i]<=90)
		{
			temp[i]=s.str[i]+32;
		}
		else
		{
			temp[i]=s.str[i];
		}
	}
	temp[s.length]='\0';
  //	cout<<"\nLowercase for the string  "<<s.str<<"  is:  "<<temp;
	String s2(temp);
	delete[]temp;
	return s2;

}

int String::equalsIgnore(String&s)
{
	String st=String::lowerCase(s);
	String me=String::lowerCase(*this);
	if(me.length!=st.length)
		{return 0;}
	for(int i=0;i<me.length;i++)
	{
		if(me.str[i]!=st.str[i])
			{return 0;}
	}
	return 1;
}

int String:: equalsIgnore(char*s){
	String st(s);
	return this->equalsIgnore(st);
}

String String::replaceText(String &s,int start,int end){

	if(end>length)
	{
		end=length;
	}

	int temp_length=(length+s.length)-((end-start)+1);
	int counter=0;
	char* temp= new char[temp_length];
	for(int i=0;i<start;i++)
	{
		temp[counter++]=str[i];
	}
	for(i=0;i<s.length;i++)
	{
		temp[counter++]=s.str[i];
	}
	for(i=end+1;i<length;i++)
	{
		temp[counter++]=str[i];
	}
	temp[counter]='\0';
 //	cout<<"\nOriginal text "<< str<<" replaced with "<<s.str <<" then it's: "<< temp;
	String s2(temp);
	delete[]temp;
	return s2;
}

String String::insertText(String&s,int start)
{
	int temp_length=s.length+length;
	int counter=0;
	char* temp= new char[temp_length+1];
	for(int i=0;i<start;i++)
	{
		temp[i]=str[i];
	}
	for(i=start;i<start+s.length;i++)
	{
		temp[i]=s.str[counter++];
	}
	counter=start+s.length;
	for(i=counter;i<temp_length;i++)
	{
		temp[i]=str[start++];
	}
	temp[temp_length]='\0';
	//cout<<"\n original text "<< str
	//<<" string to be insert "<<s.str <<" then it's: "<< temp;
	String s2(temp);
	delete[]temp;
	return s2;
}


class TestMain{

	public:
	TestMain()
	{
		clrscr();
	}
	~TestMain()
	{
		clrscr();
		cout<<"\n Main is shutting...";
	}
	test()
	{
		char * text,*text2;
		cout<<"\nEnter first string to use in operations: ";
		cin>> text;
		String m=text;
		cout<<"\nEnter another string to use in operations: ";
		cin>>text2;
		String a=text2;
		m.printString();
		cout<<endl<<"\n>> Ouput of Concatination with Hey: ";
		String mm=m.concat(" Hey");
		mm.printString();
		cout<<endl<<"\n>>Ouput of += for 2 strings: ";
		a+=m;
		a.printString();
		cout<<endl<<"\n>>Ouput of + for first and concatination Strings: ";
		String ma=m+a;
		ma.printString();
		cout<<"\n>> Index of d: "<<ma.indexOf('d');
		int l=a.stringLength();
		cout<<"\n>> String length of your second string: "<<l;
		cout<<"\n>> CharAt index 3 is:" <<a.charAt(3);
		String m_small=String::lowerCase(m);
		cout<<"\n>> LowerCase of your first String is: ";
		m_small.printString();
		cout<<"\n>> Uppercase of your first String is: ";
		String m_capital=String::upperCase(m);
		m_capital.printString();
		getch();
		clrscr();
		if(m.equalsIgnore(m_small))
		{
			cout<<"\n>> Your First string and second string after lowercase are equal";
		}
		cout<<"\n>> Substring for your second string from index 3 to 6: ";
		String substring= a.subString(3,6);
		substring.printString();
		cout<<"\n>> Test Inserting Text on your first text by inserting *insert* word: ";
		String insert=m.insertText("insert",3);
		insert.printString();
		cout<<"\n>> Test Replacing Text on your first text by second text from index 2 to 3: ";
		String replace=m.replaceText(a,2,3);
		replace.printString();
		if(m.equals(a))
		{
			cout<<"\n>> Your First and Second Strigs are equal";
		}
		else{
			cout<<"\n>> Your First and Second Strings are not equal";
		}
	}

};
int main()
{
	clrscr();
	TestMain t;
	t.test();
	getch();
	return 0;

}
