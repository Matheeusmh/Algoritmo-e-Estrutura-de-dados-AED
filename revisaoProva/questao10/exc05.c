void mist (No* li)
{
    No *p, *q;
    int f = 0;
    q = p = li;
    while (q->prox != NULL)
    {
        q = q->prox;
        if (f==1)
        {
            p = p->prox;
        }
        f = !f;
    }
    if (f==1)
        printf("%d  %d\n", p->prox->item, p->item);
    else
        printf("%d\n", p->item);
}

1 2 3 4 5 6 7 8 9 10
                  q  
        p