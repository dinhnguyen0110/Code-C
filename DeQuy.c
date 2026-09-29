Tree getPrevious(int x, Tree T) {
    if (T == NULL)
        return NULL;

    if (x <= T->Key)
        return getPrevious(x, T->Left);

    Tree temp = getPrevious(x, T->Right);

    if (temp != NULL)
        return temp;
    else
        return T;
}