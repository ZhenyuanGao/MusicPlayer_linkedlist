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






// construct the class for song.
struct Song{
    string song_title;
    string song_artist;
};
struct node;
typedef node *node_ptr;
//construct node
struct node
{
    Song song;
    node_ptr next;
    
    
};
// three different nodepointers to get access linked list.
node_ptr start,last, current;// auxiliary pointers.
// get node function to make new nodes
node_ptr get_node (string title, string artist){
    node_ptr temp = new node;
    temp->song.song_title = title;
    temp->song.song_artist = artist;
    temp->next = NULL;
    //maybe need to delete
    //temp->prev = NULL;
    return temp;
}






// add nodes to the first position of linked list
void add_first(string song_name, string artist){
    node_ptr new_node = get_node(song_name, artist);
    new_node->next = start;
    start = new_node;
    current = start;
    last = start;

}
void add_front(string song_name, string artist){
    node_ptr new_node = get_node(song_name, artist);
    
    new_node->next = start;
    start = new_node;
    last = current;
    
}


void add_last(string song_name, string artist){
   
    if(start==NULL){   

        add_first(song_name, artist);
    }
    else{
        node_ptr new_node = get_node(song_name, artist);
        // probe is a copy of start, traversing through the linked list to find the end node.
        node_ptr probe=start;
        while(probe->next!=NULL){
            probe = probe->next;
            
        }
        probe->next=new_node;
        last = new_node;
        
     
    }
   
}
//remove the first element
void remove_first(){
    node_ptr  node_to_remove;
    node_to_remove=current;
    if(current->next==NULL){
         current= current->next;
    delete node_to_remove;
        cout<<"the musiclist is currently empty\n";
        start=NULL;
    }
    else{
    current= current->next;
    start = current;
    delete node_to_remove;
    }
   
}
//Enlighten by Stack Overflow Post, how to get prev element of linked list for singly linked list.
node_ptr getPrev(){
    node_ptr curr = start;
    node_ptr prev = start;
    while(curr!=NULL){
    if(curr->song.song_title==current->song.song_title&&curr->song.song_artist==current->song.song_artist){
       return prev;
    }
        prev = curr;
        curr=curr->next;
    }
    return prev;
}
node_ptr findPrev(node_ptr p){
    node_ptr curr = start;
    node_ptr prev = start;
    while(curr!=NULL){
    if(curr->song.song_title==p->song.song_title&&curr->song.song_artist==p->song.song_artist){
       return prev;
    }
        prev = curr;
        curr=curr->next;
    }
    return prev;
}
void remove_last(){
    node_ptr  node_to_remove;
    node_ptr second_last;
    second_last=getPrev();
    node_to_remove=current;
    current= start;
    delete node_to_remove;  
    last = second_last;
    last->next = NULL;

}
void print_linked_list(){
    cout<<"The playlist is:\n";
       node_ptr  p;
        p=start;
      int i = 0;
    while(p!=NULL){
        
         cout<<i+1<<"."<<p->song.song_title;
        cout<<p->song.song_artist<<"\n";
        i++;
        p=p->next;

    }
   
    
}
void get_prev_current_next_song(){
      if(current->next!=NULL&&current!=start){
            cout<<"The current song is:"<<current->song.song_title<<current->song.song_artist<<"\n";
            cout<<"The previous song is:"<<getPrev()->song.song_title<<getPrev()->song.song_artist<<"\n";
            cout<<"The next song is:"<<current->next->song.song_title<<current->next->song.song_artist<<"\n";


        }
     
        else if(current==start)
        {
            
            cout<<"The current song is:"<<current->song.song_title<<current->song.song_artist<<"\n";
            cout<<"The previous song is:"<<last->song.song_title<<last->song.song_artist<<"\n";
            cout<<"The next song is:"<<current->next->song.song_title<<current->next->song.song_artist<<"\n";


            
        }
        else if(current->next==NULL)
        {
            cout<<"The current song is:"<<current->song.song_title<<current->song.song_artist<<"\n";
            cout<<"The previous song is:"<<getPrev()->song.song_title<<getPrev()->song.song_artist<<"\n";
            cout<<"The next song is:"<<start->song.song_title<<start->song.song_artist<<"\n";
        }
        
       
}

void get_prev_new(node_ptr a){
      if(a->next!=NULL&&a!=start){
            cout<<"The  song is:"<<a->song.song_title<<a->song.song_artist<<"\n";
            cout<<"The previous song is:"<<findPrev(a)->song.song_title<<findPrev(a)->song.song_artist<<"\n";
            cout<<"The next song is:"<<a->next->song.song_title<<a->next->song.song_artist<<"\n";


        }
     
        else if(a==start)
        {
            
            cout<<"The  song is:"<<a->song.song_title<<a->song.song_artist<<"\n";
            cout<<"The previous song is:"<<last->song.song_title<<last->song.song_artist<<"\n";
            cout<<"The next song is:"<<a->next->song.song_title<<a->next->song.song_artist<<"\n";


            
        }
        else if(a->next==NULL)
        {
            cout<<"The  song is:"<<a->song.song_title<<a->song.song_artist<<"\n";
            cout<<"The previous song is:"<<findPrev(a)->song.song_title<<findPrev(a)->song.song_artist<<"\n";
            cout<<"The next song is:"<<start->song.song_title<<start->song.song_artist<<"\n";
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
    else if(a=="print"){//command print, print all elements
        print_linked_list();
    }
    //print current song and song before and song after
    else if(a=="current"){
      get_prev_current_next_song();

    }
    
    //command delete:delete the song
    else if(a=="delete"){
        // unlinked the node when the node is not the front or the end
        if(current->next!=NULL&&current!=start){
            node_ptr probe;
            probe = current;
            node_ptr trailer = getPrev();
            trailer->next = probe->next;
            current = probe->next;
         
        }
        // if the node is at the first, and there is only one element
         else if (current->next==NULL&&current==start)
        {
            remove_first();

        }
        // if the node is at first and not only one element
          else if (current->next!=NULL&&current==start)
        {
            remove_first();

        }
        
       // last element to remove
        else if (current->next==NULL)
        {
            remove_last();
        }

       

    }
    //make previous song new current song
    else if(a=="prev"){
           if(current != start){
                 current =getPrev();

           }else if(current == start){
               current = last;
           }
           

    }
    //make a random song current song
    else if(a=="random"){
        node_ptr p=start;
        int counter =0;
        // loop through the list once to get the size of the list
        while(p!=NULL){
            counter++;
            p=p->next;

        }
        p=start;
        // loop it second times to create a random integer
        for (int i=0;i<rand() %counter;i++){
            srand (time(NULL));
            p=p->next;
        }
        current=p;
    

    }
    // command restart
    else if(a=="restart"){
        current = start;

    }
    else if(a=="q"){
        cout<<"quit is being met\n";

    }
    
    else{
        // get the command string from the user.
        string command =string(a.c_str(),a.c_str()+a.find(" "));   
        if(command=="push"&&start==NULL){
            string song_name=string(a.c_str()+a.find(" ")+1,a.c_str()+a.find("["));  
           string  artist = string(a.c_str()+a.find("["),a.c_str()+ a.size());
            add_first(song_name, artist);
            
        }
        
       else if(command=="push"&&start!=NULL){
            string song_name=string(a.c_str()+a.find(" ")+1,a.c_str()+a.find("["));  
            string  artist = string(a.c_str()+a.find("["),a.c_str()+ a.size());
            add_front(song_name, artist);
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
            if(start==NULL){
                //if there is nothing to add before
                cout<<"nothing to add before\n";
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
                //set the after node to insert node;
                trailer->next = insert_node;
                insert_node->next=target;
               

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
              if(start==NULL){
                cout<<"nothing to add after\n";
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
                // first way to build the another node
                if(target->next==NULL&&found==true){
                     insert_node = get_node(song_to_add_title,song_to_add_artist);
                //set the after node to insert node;
                insert_node->next = NULL;
                target->next = insert_node;

                }else{
                    insert_node = get_node(song_to_add_title,song_to_add_artist);
                    //set the after node to insert node;
                    insert_node->next = target->next;
                    target->next = insert_node;
             
                }
               
                
             
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
                while(target!=NULL&&! found){
                        if(target->song.song_title==song_name&&target->song.song_artist==artist){
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
            while(p!=NULL&&! found){
                        if(p->song.song_title==song_name){
                            cout<<"Here is the element you are looking for:\n";
                            get_prev_new(p);
                            found =true;
                        }else{
                            p = p->next;

                        }

                }
                if(found==false){
                    cout<<"the element does not exist\n";
                }


            if(found==false){
                cout<<"the element you look for is not there.\n";
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