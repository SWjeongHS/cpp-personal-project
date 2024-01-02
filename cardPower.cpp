int cardPower(int card1, int card2){
    int powerValue=0;
    int value = card1 * card2;
    //powerValue information
    //0~9   == 1~10ggeut
    //10    == seryuk
    //11    == jangsa
    //12    == jangbbing
    //13    == gubbing
    //14    == doksa
    //15    == ali
    //16~25 == 1~10ddaeng
    //26~28 == 13,18,38 gwangddang
    //29    == ddanghunter
    //30    == gwangddanghunter
    //31    == gusa
    //32    == munggusa
    if(value==295||value==305||value==517||value==583||value==611||value==713||value==851||value==899||value==1073||value==413||value==427){
        //1ggeut//1ggeut//1ggeut//1ggeut//1ggeut//1ggeut//1ggeut//1ggeut//1ggeut//1ggeut//1ggeut//1ggeut//1ggeut//1ggeut//1ggeut//1ggeut//1ggeut//1ggeut//1ggeut//1ggeut//1ggeut//1ggeut//1ggeut
        powerValue = 0;
    }
    else if(value==335||value==355||value==649||value==671||value==767||value==793||value==799||value==901||value==893||value==1007||value==943||value==989||value==1189||value==1247||value==469||value==497){
        //2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut//2ggeut
        powerValue = 1;
    }
    else if(value==737||value==781||value==871||value==923||value==1081||value==1219||value==1363||value==1537||value==1271||value==1333||value==1517||value==1591){
        //3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut//3ggeut
        powerValue = 2;        
    }
    else if(value==22||value==26||value==33||value==1357||value==1403||value==1711||value==1769||value==1457||value==1643||value==1739||value==1961){
        //4ggeut//4ggeut//4ggeut//4ggeut//4ggeut//4ggeut//4ggeut//4ggeut//4ggeut//4ggeut//4ggeut//4ggeut//4ggeut//4ggeut//4ggeut//4ggeut//4ggeut//4ggeut//4ggeut
        powerValue = 3;
    }
    else if(value==55||value==65||value==77||value==91||value==1541||value==1633||value==1943||value==2059||value==1829||value==1891||value==2183||value==2257||value==1927||value==2173||value==2021||value==2279){
        //5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut//5ggeut
        powerValue = 4;
    }
    else if(value==46||value==58||value==69||value==87||value==85||value==95||value==119||value==133||value==2077||value==2201||value==2479||value==2627||value==2419||value==2501||value==2537||value==2623){
        //6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut//6ggeut
        powerValue = 5;
    }
    else if(value==62||value==74||value==93||value==111||value==115||value==145||value==161||value==203||value==187||value==209||value==221||value==247||value==2747||value==2911||value==2881||value==3053||value==2773||value==2867||value==3127||value==3233){
        //7ggeut//7ggeut//7ggeut//7ggeut//7ggeut//7ggeut//7ggeut//7ggeut//7ggeut//7ggeut//7ggeut//7ggeut//7ggeut//7ggeut//7ggeut//7ggeut//7ggeut//7ggeut//7ggeut//7ggeut//7ggeut//7ggeut//7ggeut//7ggeut
        powerValue = 6;
    }
    else if(value==82||value==86||value==123||value==129||value==155||value==185||value==217||value==259||value==253||value==319||value==299||value==377||value==3149||value==3337||value==3551||value==3763){
        //8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut//8ggeut
        powerValue = 7;
    }
    else if(value==94||value==106||value==141||value==205||value==215||value==287||value==301||value==341||value==407||value==403||value==481||value==391||value==493||value==437||value==551||value==3953||value==4189||value==4087||value==4331){
        //9ggeut//gaboh//9ggeut//gaboh//9ggeut//gaboh//9ggeut//gaboh//9ggeut//gaboh//9ggeut//gaboh//9ggeut//gaboh//9ggeut//gaboh//9ggeut//gaboh//9ggeut//gaboh//9ggeut//gaboh//9ggeut//gaboh//9ggeut//gaboh//9ggeut//gaboh//9ggeut//gaboh//9ggeut//gaboh
        powerValue = 8;
    }
    else if(value==235||value==265||value==329||value==371){
        //10ggeut//mangtong//10ggeut//mangtong//10ggeut//mangtong
        powerValue = 9;
    }
    else if(value==527||value==629||value==589||value==703){
        //seryuk
        powerValue = 10;
    }
    else if(value==1139||value==923||value==1273||value==1349){
        //jangsa
        powerValue = 11;
    }
    else if(value==134||value==142||value==201||value==213){
        //jangbbing
        powerValue = 12;
    }
    else if(value==118||value==122||value==177||value==183){
        //gubbing
        powerValue = 13;
    }
    else if(value==34||value==38||value==51||value==57){
        //doksa
        powerValue = 14;
    }
    else if(value==10||value==14||value==15||value==21){
        //ali
        powerValue = 15;
    }
    else if(value==6){
        //1ddaeng
        powerValue = 16;
    }
    else if(value==35){
        //2ddaeng
        powerValue = 17;
    }
    else if(value==143){
        //3ddaeng
        powerValue = 18;
    }
    else if(value==323){
        //4ddaeng
        powerValue = 19;
    }
    else if(value==667){
        //5ddaeng
        powerValue = 20;
    }
    else if(value==1147){
        //6ddaeng
        powerValue = 21;
    }
    else if(value==1763){
        //7ddaeng
        powerValue = 22;
    }
    else if(value==2491){
        //8ddaeng
        powerValue = 23;
    }
    else if(value==3599){
        //9ddaeng
        powerValue = 24;
    }
    else if(value==4757){
        //10ddaeng
        powerValue = 25;
    }
    else if(value==39){
        //13gwangddaeng
        powerValue = 26;
    }
    else if(value==159){
        //18gwangddaeng
        powerValue = 27;
    }
    else if(value==689){
        //38gwangddaeng
        powerValue = 28;
    }
    else if(value==451||value==473||value==533||value==559){
        //ddanghunter
        powerValue = 29;
    }
    else if(value==697||value==731||value==779||value==817){
        //gwangddanghunter
        powerValue = 30;
    }
    else if(value==1003||value==1037||value==1121){
        //gusa
        powerValue = 31;
    }
    else if(value==1159){
        //munggusa
        powerValue = 32;
    }
    return powerValue;
}