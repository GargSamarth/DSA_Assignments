void print(lptr1 ML){

    if(ML != NULL){

        cout<< ML->data<< " ";

        if(ML->dlink != NULL){

            lptr2 T = ML->dlink;

            while(T != NULL){
                cout<< T->data << " ";
                T = T->dlink;
            }

        }

        print(ML->next);
    }

}