int height(node* node){
    queue<node*> q;
    q.push(root);
    p.push(NULL);
    int h=1;

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if (temp == NULL){
            h++;
            if (q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
    return h;
}