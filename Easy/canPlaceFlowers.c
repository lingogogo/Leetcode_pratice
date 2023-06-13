bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    // count the space to 
    int con = 0;
    int i = 1;
    
    if(flowerbed[0] == 0 && flowerbedSize == 1 && n <=1) return true;
    else if(flowerbed[0] == 1 && flowerbedSize == 1 && n > 0) return false;
    else if(n == 0) return true;

    if(flowerbed[0] == 0 && flowerbed[1] == 0){
        con++;
        flowerbed[0] = 1;
    } 
    if(flowerbed[flowerbedSize - 1] == 0 && flowerbed[flowerbedSize - 2] == 0)
    {
        con++;
        flowerbed[flowerbedSize - 1] = 1;
    } 

    while(i < flowerbedSize - 1)
    {
        
        if(flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
        {
            con = con + 1;
            i = i + 2;
            continue;
        } 
        i++;
    }

    if(n>con) return false;
    else return true;

}
