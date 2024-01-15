#include <iostream>
#include<fstream>

using namespace std;

struct item {
    string name;
    string lastName;
    int facultyNumber;
    item* next;
} *front=NULL;

void insert_l(string name, string lastName, int facultyNumber) 
{	
    item* newitem = new item;
    newitem->name=name;
    newitem->lastName=lastName;
    newitem->facultyNumber=facultyNumber;
    cout<<"Vuvedete student:";
      cin>>(newitem->name);
       cin>>(newitem->lastName);
 	cout<<"Vuvedete fakulteten nomer:";
      cin>>(newitem->facultyNumber);
    if ( front==NULL || front->name>=newitem->name || front->facultyNumber>=newitem->facultyNumber)
	{
		newitem->next=front;
		front = newitem;
	}
    else
	{
		item *curr = front;
		item* prev;
		while ( curr != NULL && curr->name<name ) 
		{ 
    		prev=curr;
    		curr=curr->next;
		}
		prev->next=newitem;
		newitem->next=curr;
    } 
}

void search_l(string name, string lastName, int facultyNumber)
{	
	cout<<"Vuvedete fakulteten nomer:";
    cin>>(facultyNumber);
    item* curr = front;
    item* prev=NULL; 
    while (curr!= NULL &&  curr->facultyNumber != facultyNumber) 
    {
    	prev=curr;
        curr = curr->next; 
    }
    if (curr==NULL)  
		cout<<"Studentyt ne e nameren"<<endl;
	else 
    {
          cout<<curr->name<<" "<<curr->lastName<<", "<<facultyNumber<<endl;  
   } 	
}


void delete_l(string name, string lastName, int facultyNumber)
{			
	
 	cout<<"Vuvedete fakulteten nomer:";
    cin>>(facultyNumber);
    if (front == NULL) 
    {
    	cout<<"empty list";
        return; 
	}
	item* curr = front;
    item* prev=NULL; 
    while (curr!= NULL &&  curr->facultyNumber != facultyNumber)
    {
    	prev=curr;
        curr = curr->next; 
    }
    if (curr==NULL)  
		cout<<"Studentyt ne e nameren"<<endl;
	else 
    {
          cout<<curr->name<<" "<<curr->lastName<<", "<<facultyNumber<<" is deleted"<<endl;
	    if(prev==NULL)
			front=front->next;
		else
			prev->next=curr->next;
    	delete curr;
   } 
}

void save_to_file(string name, string lastName, int facultyNumber) {	
	item* curr = front;
    item* prev=NULL; 
 fstream fi("List.txt", ios::app);
 
  if (fi.is_open())
    { 
	cout<<"Zapisvane vuv file..."<<endl; 
	while(curr!=NULL)
      {		

        fi <<"\nIme na student: " << curr->name<<" "<<curr->lastName<<endl;
        fi <<"\nFakulteten nomer: " <<curr->facultyNumber<<endl;
        curr = curr->next; 
		
      
    }
	cout<<"Studentite sa zapisani\n";

    	fi.close();	 
	}
	else cout << "Unable to open file";
}



int main()
{
	string name;
	string lastName;
    int facultyNumber;

     char ch;
     do
      {
	cout<< "1. Dobavqne na student\n2. Premahvane na student\n3. Izvezhdane na student\n4. Zapis vuv file\n5.Izhod\nIzberete... ";
            cin>>ch;
            switch(ch)
            {
                  case '1': 
				  insert_l(name, lastName, facultyNumber);
				  break;
                  case '2':
				   delete_l(name, lastName, facultyNumber);
				   break;
                  case '3':
				   search_l( name, lastName, facultyNumber);
				   break;
                  case '4': 
				  save_to_file(name, lastName, facultyNumber); 
				  break;
            }
      }
	  while(ch!='5');
}

