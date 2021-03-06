#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<array>
#include<vector>
#include<math.h>
#include<sstream>

using namespace std;

string test_title;


// upgrade version of MusicPlaylist. Add a new prev attribute for double linked list
// upgrade the find so that we do not need to go though the list two times.
//add a tracker for length of the linked list


int length = 0;

struct Song{
    string song_title;
    string song_artist;
};
struct node;
typedef node *node_ptr;

struct node
{
    Song song;
    node_ptr next;
    node_ptr prev;
    
};

node_ptr start,last, current;// auxiliary pointers.
node_ptr get_node (string title, string artist){
    node_ptr temp = new node;
    temp->song.song_title = title;
    temp->song.song_artist = artist;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}






void add_first(string song_name, string artist){
    node_ptr new_node = get_node(song_name, artist);
    new_node->next = start;
    new_node->prev = start;//watch this out
    start = new_node;
    current = start;
    last = start;
    length++;
}
void add_front(string song_name, string artist){
    node_ptr new_node = get_node(song_name, artist);
    
    new_node->next = start;
    start->prev = new_node;
    start = new_node;
    last = current;
    length++;
}


void add_last(string song_name, string artist){
    if(length==0){
        add_first(song_name, artist);
    }
    else{
        node_ptr new_node = get_node(song_name, artist);
        // probe is a copy of start, traversing through the linked list to find the end node.
        node_ptr probe=last;
        //implement the counter to achieve O(1) time.
        probe->next=new_node;
        new_node->prev=last;
        last = new_node;
        new_node->next=NULL;        
        length++;
    }
   
}

void remove_first(){
    node_ptr  node_to_remove;
    node_to_remove=current;

   
    if(current->prev==NULL&&current->next==NULL){
         current= current->next;
        delete node_to_remove;
        cout<<"the musiclist is currently empty\n";
        start=NULL;
    }
    else{
    current= current->next;
    delete node_to_remove;
    current->prev=last;
    }
   
    length--;
}


void get_current_find(node_ptr current){
     if(current->prev!=NULL&&current->next!=NULL){
            cout<<"The song is found:"<<current->song.song_title<<current->song.song_artist<<"\n";
            cout<<"The previous song is:"<<current->prev->song.song_title<<current->prev->song.song_artist<<"\n";
            cout<<"The next song is:"<<current->next->song.song_title<<current->next->song.song_artist<<"\n";


        }
       else if (current->prev==NULL&&current->next==NULL){
            
            cout<<"The song is found:"<<current->song.song_title<<current->song.song_artist<<"\n";
            cout<<"The previous song is:"<<current->song.song_title<<current->song.song_artist<<"\n";
            cout<<"The next song is:"<<current->song.song_title<<current->song.song_artist<<"\n";


        }
        
        
        else if(current->prev==NULL)
        {
            cout<<"The song is found:"<<current->song.song_title<<current->song.song_artist<<"\n";
            cout<<"The previous song is:"<<last->song.song_title<<last->song.song_artist<<"\n";
            cout<<"The next song is:"<<current->next->song.song_title<<current->next->song.song_artist<<"\n";


            
        }
        else if(current->next==NULL)
        {
            cout<<"The song is found:"<<current->song.song_title<<current->song.song_artist<<"\n";
            cout<<"The previous song is:"<<current->prev->song.song_title<<current->prev->song.song_artist<<"\n";
            cout<<"The next song is:"<<start->song.song_title<<start->song.song_artist<<"\n";


            
        }
        
       
}


void remove_last(){
    node_ptr  node_to_remove;
    node_to_remove=current;
    last = current->prev;
    last->next = NULL;
     current= start;
    delete node_to_remove;
    current->prev=last;
    length--;

}
void print_linked_list(){
    cout<<"The playlist is:\n";
       node_ptr  p;
        p=start;
       
    if(p==NULL){

        while(p!=NULL){
            int i = 0;
            cout<<i+1<<"."<<p->song.song_title;
            cout<<p->song.song_artist<<"\n";
            p=p->next;
            i++;

    }
    
    }else{
        if(p->prev ==NULL&&length!=0){
            p->prev=last;
        }
        int i = 0;
        while(p!=NULL){
        
            cout<<i+1<<"."<<p->song.song_title;
            cout<<p->song.song_artist<<"\n";
            p=p->next;
            i++;

        }
    
    }

}

void evaluate_command(string a){
    if(a=="next"){//command next, make next song current
       if(current->next!=NULL){

           current = current->next;

       }else{
           current = start;
       }
       
    }
    // print all songs
    else if(a=="print"){
        print_linked_list();

    }
    //print current song and song before and song after
    else if(a=="current"){
        if(current->prev!=NULL&&current->next!=NULL){
            cout<<"The current song is:"<<current->song.song_title<<current->song.song_artist<<"\n";
            cout<<"The previous song is:"<<current->prev->song.song_title<<current->prev->song.song_artist<<"\n";
            cout<<"The next song is:"<<current->next->song.song_title<<current->next->song.song_artist<<"\n";


        }
       else if (current->prev==NULL&&current->next==NULL){
            
            cout<<"The current song is:"<<current->song.song_title<<current->song.song_artist<<"\n";
            cout<<"The previous song is:"<<current->song.song_title<<current->song.song_artist<<"\n";
            cout<<"The next song is:"<<current->song.song_title<<current->song.song_artist<<"\n";


        }
        
        else if(current->prev==NULL)
        {
            cout<<"The current song is:"<<current->song.song_title<<current->song.song_artist<<"\n";
            cout<<"The previous song is:"<<last->song.song_title<<last->song.song_artist<<"\n";
            cout<<"The next song is:"<<current->next->song.song_title<<current->next->song.song_artist<<"\n";


            
        }
        else if(current->next==NULL)
        {
            cout<<"The current song is:"<<current->song.song_title<<current->song.song_artist<<"\n";
            cout<<"The previous song is:"<<current->prev->song.song_title<<current->prev->song.song_artist<<"\n";
            cout<<"The next song is:"<<start->song.song_title<<start->song.song_artist<<"\n";


            
        }
        
       

    }
    
    //delete the song
    else if(a=="delete"){
        if(current->prev!=NULL&&current->next!=NULL){
            current->prev->next=current->next;
            current= current->next;
            length--;

        }
         else if (current->next==NULL&&current->prev==NULL)
        {
            remove_first();

        }
        
        else if (current->prev==NULL)
        {
            remove_first();
        }
         
        else if (current->next==NULL)
        {
            remove_last();
        }

       

    }
    //make previous song new current song
    else if(a=="prev"){
        if(current->prev!=NULL)
            current=current->prev;
        else
            current=last;

    }
    //make a random song current song
    else if(a=="random"){
        node_ptr p;
        for (int i=0;i<rand() %length;i++){
            p=p->next;
        }
        current=p;
    cout<<"current"<<current->song.song_title<<"\n";

    }
    else if(a=="restart"){
        current = start;

    }
    
    else{
        string command =string(a.c_str(),a.c_str()+a.find(" "));   
        
       
        if(command=="push"&&start==NULL){
            string song_name=string(a.c_str()+a.find(" ")+1,a.c_str()+a.find("["));  
           string  artist = string(a.c_str()+a.find("["),a.c_str()+ a.size());
            add_first(song_name, artist);//in the future, might consider make two parameter;
           
            
        }
        
       else if(command=="push"&&start!=NULL){
            string song_name=string(a.c_str()+a.find(" ")+1,a.c_str()+a.find("["));  
            string  artist = string(a.c_str()+a.find("["),a.c_str()+ a.size());
            add_front(song_name, artist);//in the future, might consider make two parameter;
          
        }

        if(command=="queue"){
            string song_name=string(a.c_str()+a.find(" ")+1,a.c_str()+a.find("["));  
            string artist = string(a.c_str()+a.find("["),a.c_str()+ a.size());
            add_last(song_name,artist);
            
        }
          if(command=="addBefore"){
            string song_name=string(a.c_str()+a.find(" ")+1,a.c_str()+a.find("["));  
            a=a.substr(a.find("]")+1,a.size());

            string song_to_add_title=string(a.c_str()+a.find(" ")+1,a.c_str()+a.find("["));  
            string song_to_add_artist=string(a.c_str()+a.find("["),a.c_str()+a.size());  
            node_ptr target = start;
            node_ptr insert_node;
            node_ptr trailer;
            bool found = false;
            if(current==NULL){
                //if there is nothing to add before
                cout<<"nothing to add before";
                exit(3);
            }
            else if(trailer==NULL&&target->song.song_title==song_name){
                add_front(song_to_add_title,song_to_add_artist);

            }
            else {
                //traversing the whole linked list to look for the target element
                while(target->next!=NULL&&! found){
                        if(target->song.song_title==song_name){
                            found =true;

                        }else{
                            trailer = target;
                            target = target->next;

                        }

                }
                insert_node = get_node(song_to_add_title,song_to_add_artist);
                trailer->next = insert_node;
                target->prev = insert_node;
                insert_node->prev = trailer;
                insert_node->next=target;
                insert_node->next->prev=insert_node;
                length++;

            }
            
         
        }
         if(command=="addAfter"){
            string song_name=string(a.c_str()+a.find(" ")+1,a.c_str()+a.find("["));  
            a=a.substr(a.find("]")+1,a.size());
            string song_to_add_title=string(a.c_str()+a.find(" ")+1,a.c_str()+a.find("["));  
            string song_to_add_artist=string(a.c_str()+a.find("["),a.c_str()+a.size());  
            node_ptr target = start;
            node_ptr insert_node;
            node_ptr trailer;
            bool found = false;
            if(length==0){
                cout<<"nothing to add after";
                exit(3);
            }
           
            else {
                //traversing the whole linked list to look for the target element
                while(target!=NULL&&! found){
                        if(target->song.song_title==song_name){
                            found =true;

                        }else{
                            trailer = target;
                            target = target->next;

                        }

                }
                if( target==NULL&&found==false){
                    cout<<"the song you are trying to add after does not exist. Can not add it\n";
                    exit(3);
                }
                if(target->next==NULL&&found==true){
                     insert_node = get_node(song_to_add_title,song_to_add_artist);
                //set the after node to insert node;
                insert_node->next = NULL;
                target->next = insert_node;
                insert_node->prev = target;
                target->prev = trailer;

                }else{
                     insert_node = get_node(song_to_add_title,song_to_add_artist);
                //set the after node to insert node;
                insert_node->next = target->next;
                target->next = insert_node;
                insert_node->prev = target;
                target->prev = trailer;
                //when insertNode is not the last element in the linked list;
                 insert_node->next->prev=insert_node;

                }
                length++;

            }
            
        }
        if(command == "changeTo"){
            string song_name=string(a.c_str()+a.find(" ")+1,a.c_str()+a.find("["));  
            string  artist = string(a.c_str()+a.find("["),a.c_str()+ a.size());
            node_ptr target = start;
            node_ptr insert_node;
            node_ptr trailer;
            bool found = false;
                //traversing the whole linked list to look for the target element
                while(target->next!=NULL&&! found){
                        if(target->song.song_title==song_name){
                            found =true;

                        }else{
                            trailer = target;
                            target = target->next;

                        }

                }
                if(found==false){
                    cout<<"the element does not exist";
                }

                current = target;



        }
        if(command =="find"){
            string song_name=string(a.c_str()+a.find(" ")+1,a.c_str()+a.find("["));  
            string  artist = string(a.c_str()+a.find("["),a.c_str()+ a.size());

            node_ptr  p;
            p=start;
            bool found = false;
            for(int i=0;i<length;i++){
               
                 if(p->song.song_title==song_name){
                    get_current_find(p);
                    found = true;
                    }
                p=p->next;

            }
            if(found==false){
                cout<<"the element you look for to change is not there.\n";
            }
        }
       
    }
};


void get_the_input(){
        while(test_title!="q"){
            cout<<"Please input your command here: ";
            getline(cin,test_title);
        
       evaluate_command(test_title);
        }
        
}

int main(){
    get_the_input();

    return 0;
}