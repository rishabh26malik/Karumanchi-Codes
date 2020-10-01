// what we Have To Do  
//1->3->4 = 100+30+4=134

  struct Node* addTwoLists(struct Node* first, struct Node* second)
      {
         // code here
         
         int i=1;
         
         struct Node*temp=first;
         int count=0;
         while(temp!=NULL)
         {
         //    i=i*10;
            i=i*10;
            temp=temp->next;
            count++;
         }
         i=i/10;
         cout<<"Main Value:"<<i<<endl;
         
         
         int sum=0;
         
         temp=first;
         
         while(temp!=NULL){
            
            int jtemp=temp->data;
            sum=sum+jtemp*i;
            i=i/10;
            temp=temp->next;
         }
         
         cout<<sum<<"kk"<<endl;
         

         return first;
         
         
         
         
         
      }
