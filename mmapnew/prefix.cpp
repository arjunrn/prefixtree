/**
 * Created by mina on 22.09.15.
 */
#include "prefix.h"
#include <sys/mman.h>
#include <stdint.h>

using namespace std;

Trie::Trie() {
    this->nodecount++;
    //this->root = root;
    this->nodecount = 0;
    this->overallnodecount = 0;
    this->nodesize = sizeof(root);
    for (int i = 0; i < 1111; i++)
        this->corrupted[i] = 0;
    ccorrupt = 0;
    this->countcorrupt = 0;


}

Trie::~Trie() {
    //delete root;
}

void Trie::createTrie() {
    cout<<"Size of int is"<<sizeof(uint8_t);
    u_int64_t addressi;
    void *address;
    size_t length;
    //size_t length = 36650387584;
    length = 64;//16*4
    address = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if (address == MAP_FAILED)
        cout << "mmap was not successfull!!" << endl;
    this->root = (u_int64_t) address;

    length = 1154; //256*4+2+16*8
    address = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if (address == MAP_FAILED)
        cout << "mmap was not successfull!!" << endl;
    this->firstlevel = (u_int64_t) address;

    length = 18464;// 256*16*4+32+256*8 // 8 is the size of key,value pair
    address = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if (address == MAP_FAILED)
        cout << "mmap was not successfull!!" << endl;
    this->secondlevel = (u_int64_t) address;

    length = 295424;//256*256*4+16*32+256*16*8
    address = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if (address == MAP_FAILED)
        cout << "mmap was not successfull!!" << endl;
    this->thirdlevel = (u_int64_t) address;

    length = 4726784;//256*256*16*4+256*32+256*256*8
    address = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if (address == MAP_FAILED)
        cout << "mmap was not successfull!!" << endl;
    this->fourthlevel = (u_int64_t) address;

    length = 75628544;//256*256*256*4+256*256*2+256*256*16*8
    address = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if (address == MAP_FAILED)
        cout << "mmap was not successfull!!" << endl;
    this->fifthlevel = (u_int64_t) address;

    length = 1210056704;//256*256*256*16*4+256*256*16*2+256*256*256*8
    address = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if (address == MAP_FAILED)
        cout << "mmap was not successfull!!" << endl;
    this->sixthlevel = (u_int64_t) address;

 length = 2151677952;//256*256*256*16*8+256*256*64
 address = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
 if (address == MAP_FAILED)
     cout << "mmap was not successfull!!" << endl;
 this->seventhlevel = (u_int64_t) address;

 length =2151677952;
 address = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
 if (address == MAP_FAILED)
     cout << "mmap was not successfull!!" << endl;
 this->seven1level = (u_int64_t) address;

 length = 2151677952;
 address = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
 if (address == MAP_FAILED)
     cout << "mmap was not successfull!!" << endl;
 this->seven2level = (u_int64_t) address;

 length =2151677952;
 address = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
 if (address == MAP_FAILED)
     cout << "mmap was not successfull!!" << endl;
 this->seven3level = (u_int64_t) address;

 length = 2151677952;
 address = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
 if (address == MAP_FAILED)
     cout << "mmap was not successfull!!" << endl;
 this->seven4level = (u_int64_t) address;

 length =2151677952;
 address = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
 if (address == MAP_FAILED)
     cout << "mmap was not successfull!!" << endl;
 this->seven5level = (u_int64_t) address;

 length = 2151677952;
 address = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
 if (address == MAP_FAILED)
     cout << "mmap was not successfull!!" << endl;
 this->seven6level = (u_int64_t) address;

 length = 2151677952;//nodes+1 bit flag for all the nodes in this sublevel
 address = mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
 if (address == MAP_FAILED)
     cout << "mmap was not successfull!!" << endl;
 this->seven7level = (u_int64_t) address;

 length =2147483648;//16*16*16*16*16*16*16*8
 address=mmap(0, length, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
 if (address == MAP_FAILED)
     cout << "mmap was not successfull!!" << endl;
 this->extra = (u_int64_t) address;
}

void Trie::addKeyValue(const u_int32_t key, u_int32_t value) {

    u_int32_t bits = key;
    u_int32_t key1 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key2 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key3 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key4 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key5 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key6 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key7 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key8 = bits & 0x0000000F;
    vari1=this->root;
    vari2=this->firstlevel;
    u_int64_t cons=1024;
    u_int32_t constantkey1=key1;
    par1=key1;
    extr=par1*4;
    extr2=par1*8;
    extr3=par1;
    extr4=2;
    for(int i=0;i<8;i++) {

        if(i<6) {

              if(*(u_int32_t *) (vari1 + extr)==0 )
              {//this condition means that the address was not initialized before
                 int flagbyte=extr3/8;
                 int flagbit=extr3%8;

                 u_int8_t bytee=*(u_int8_t *)(vari2+cons+flagbyte);
                 bytee=this->getByte(flagbit,bytee);
                 if(bytee==1)
                  {
                  }
                  else {
                      *(u_int32_t *) (vari1 + extr) = cons + extr2+extr4;

                      u_int64_t res = (u_int64_t) key & 0x00000000FFFFFFFF;
                      res = res << 32;
                      res = res & 0xFFFFFFFF00000000;
                      res = value ^ res;
                      *(u_int64_t *) (vari2 + cons + extr2+extr4) = res;

                     /*u_int64_t test=vari2 + cons + extr2+extr4;
                     u_int64_t test1=cons;
                     u_int64_t test2=extr2;
                     u_int64_t test3=extr4;
                     u_int64_t test5=extr;
                     u_int64_t test6=*(u_int32_t *) (vari1 + extr);*/
                      break;
                  }
              }
                 else if(*(u_int32_t *) (vari1 + extr)< cons)
                  {}
                  else if(*(u_int32_t *) (vari1 + extr)> cons){
                      u_int32_t inter = *(u_int32_t *)(vari1 + extr);
                      u_int64_t check =extr;
                      u_int64_t res=*(u_int64_t *)(inter + vari2);
//                      u_int64_t res=*(u_int64_t *)((u_int64_t )(*(u_int64_t *) (vari1 + extr))+vari2);
                      u_int32_t newvalue= res & 0x00000000FFFFFFFF;
                      res=res >> 32;
                      u_int32_t newkey=(u_int32_t) res;
                      //TODO we have to remove the u_int64_t test=cons;allocated memory for key/value pair
                      *(u_int32_t *) (vari1 + extr) =  extr * 16;
                      int neww=extr3;
                      int flagbyte=neww/8;
                      int flagbit=neww%8;
                      u_int8_t bytee=*(u_int8_t *)(vari2+cons+flagbyte);
                      bytee=this->setByte(flagbit,bytee);
                      *(u_int8_t *)(vari2+cons+flagbyte)=bytee;
                      extr4p=extr4;
                      this->addKeyValue(newkey,newvalue);
                      extr4=extr4p;
                  }

          }
        else if (i==6)
        {
              //at first we have to check if the node in the sublevel is set or not,so:
                cons = 256 * 256 * 256 * 16 * 8;
                extr3=this->getextr3(extr3);
                int flagbyte=extr3/8;
                int flagbit=extr3%8;

                u_int8_t bytee=*(u_int8_t *)(vari2+cons+flagbyte);
                bytee=this->getByte(flagbit,bytee);
                if(bytee==1)
                {

                }
                else{//node is not set in the sublevel, so key,value pair can be set in the extra
                    u_int64_t num=*(u_int64_t *)(this->extra+extr2);
                    if(num==0)// it means that 0 means null, so no key has been inserted till here, so we have to insert it as key,value pair
                    {
                        u_int64_t res = (u_int64_t) key & 0x00000000FFFFFFFF;
                        res = res << 32;
                        res = res & 0xFFFFFFFF00000000;
                        res = value ^ res;
                        *(u_int64_t *) (this->extra + extr2)=res;
                        *(u_int32_t *) (vari1 + extr)=extr2;
                        break;

                    }
                    else //key value pair is set here, so we have to delete it from here and create a node in the correct place
                    {
                        cons= 256 * 256 * 256 * 16 * 8;
                        u_int32_t inter = *(u_int32_t *) (vari1 + extr);
                        u_int64_t res = *(u_int64_t *) (inter + this->extra);
                        u_int32_t newvalue = res & 0x00000000FFFFFFFF;
                        res = res >> 32;
                        u_int32_t newkey = (u_int32_t) res;
                        //now we have to set the flag bit in the correct place in the correct sublevel
                        extr2=extr*16;
                        extr2=this->getextr4(extr2);
                        *(u_int32_t *) (vari1 + extr) = extr2;
                        int neww=extr2/64;
                        int flagbyte=neww/8;
                        int flagbit=neww%8;
                        u_int8_t bytee=*(u_int8_t *)(vari2+cons+flagbyte);
                        bytee=this->setByte(flagbit,bytee);
                        *(u_int8_t *)(vari2+cons+flagbyte)=bytee;
                        extr4p=extr4;
                        this->addKeyValue(newkey,newvalue);
                        extr4=extr4p;
                    }

                }
        }
        else //i==7
        {
            extr=this->getextr4(extr);
            *(u_int32_t *)(vari2+extr)=value;

        }


          switch(i){
            case 0  :
                vari1 =this->firstlevel;
                vari2 =this->secondlevel;
                key1=key1*16;
                par1=key1;
                par2=key2;
                cons=cons*16;
                extr=par1*4+par2*4;
                extr2=par1*8+par2*8;
                extr3=par1+par2;
                extr4=extr4*16;
                break; //optional
            case 1  :
                vari1 =this->secondlevel;
                vari2 =this->thirdlevel;
                key1=key1*16;
                key2=key2*16;
                par1=key1;
                par2=key2;
                par3=key3;
                cons=cons*16;
                extr=par1*4+par2*4+par3*4;
                extr2=par1*8+par2*8+par3*8;
                  extr3=par1+par2+par3;
                  extr4=extr4*16;
                break; //optional
            case 2  :
                vari1 =this->thirdlevel;
                vari2 =this->fourthlevel;
                key1=key1*16;
                key2=key2*16;
                key3=key3*16;
                par1=key1;
                par2=key2;
                par3=key3;
                par4=key4;
                cons=cons*16;
                extr=par1*4+par2*4+par3*4+par4*4;
                extr2=par1*8+par2*8+par3*8+par4*8;
                  extr3=par1+par2+par3+par4;
                  extr4=extr4*16;
                break;
            case 3  :
                vari1 =this->fourthlevel;
                vari2 =this->fifthlevel;
                key1=key1*16;
                key2=key2*16;
                key3=key3*16;
                key4=key4*16;
                par1=key1;
                par2=key2;
                par3=key3;
                par4=key4;
                par5=key5;
                cons=cons*16;
                extr=par1*4+par2*4+par3*4+par4*4+par5*4;
                extr2=par1*8+par2*8+par3*8+par4*8+par5*8;
                  extr3=par1+par2+par3+par4+par5;
                  extr4=extr4*16;
                break;
            case 4  :
                vari1 =this->fifthlevel;
                vari2 =this->sixthlevel;
                key1=key1*16;
                key2=key2*16;
                key3=key3*16;
                key4=key4*16;
                key5=key5*16;
                par1=key1;
                par2=key2;
                par3=key3;
                par4=key4;
                par5=key5;
                par6=key6;
                cons=cons*16;
                extr=par1*4+par2*4+par3*4+par4*4+par5*4+par6*4;
                extr2=par1*8+par2*8+par3*8+par4*8+par5*8+par6*8;
                  extr3=par1+par2+par3+par4+par5+par6;
                  extr4=extr4*16;
                break;
            case 5  :
                vari1 =this->sixthlevel;
                key1=key1*16;
                key2=key2*16;
                key3=key3*16;
                key4=key4*16;
                key5=key5*16;
                key6=key6*16;
                par1=key1;
                par2=key2;
                par3=key3;
                par4=key4;
                par5=key5;
                par6=key6;
                par7=key7;
                cons=cons*16;
                if(constantkey1<2)
                    vari2=this->seventhlevel;
                if(1<constantkey1 and constantkey1<4)
                    vari2 =this->seven1level;

                if(3<constantkey1 and constantkey1<6)
                    vari2 =this->seven2level;

                if(5<constantkey1 and constantkey1<8)
                    vari2 =this->seven3level;

                if(7<constantkey1 and constantkey1<10)
                    vari2 =this->seven4level;

                if(9<constantkey1 and constantkey1<12)
                    vari2 =this->seven5level;

                if(11<constantkey1 and constantkey1<14)
                    vari2 =this->seven6level;

                if(13<constantkey1 and constantkey1<16)
                    vari2 =this->seven7level;

                extr=par1*4+par2*4+par3*4+par4*4+par5*4+par6*4+par7*4;
                extr1=par2*4+par3*4+par4*4+par5*4+par6*4+par7*4;
                extr2=par1*8+par2*8+par3*8+par4*8+par5*8+par6*8+par7*8;
                extr3=par1+par2+par3+par4+par5+par6+par7;
                extr4=extr4*16;
                break;
              case 6  :
                  key1=key1*16;
                  key2=key2*16;
                  key3=key3*16;
                  key4=key4*16;
                  key5=key5*16;
                  key6=key6*16;
                  key6=key6*16;
                  key7=key7*16;
                  par1=key1;
                  par2=key2;
                  par3=key3;
                  par4=key4;
                  par5=key5;
                  par6=key6;
                  par7=key7;
                  par8=key8;
                  cons=cons*16;
                  if(constantkey1<2)
                      vari2=this->seventhlevel;
                  if(1<constantkey1 and constantkey1<4)
                      vari2 =this->seven1level;

                  if(3<constantkey1 and constantkey1<6)
                      vari2 =this->seven2level;

                  if(5<constantkey1 and constantkey1<8)
                      vari2 =this->seven3level;

                  if(7<constantkey1 and constantkey1<10)
                      vari2 =this->seven4level;

                  if(9<constantkey1 and constantkey1<12)
                      vari2 =this->seven5level;

                  if(11<constantkey1 and constantkey1<14)
                      vari2 =this->seven6level;

                  if(13<constantkey1 and constantkey1<16)
                      vari2 =this->seven7level;
                  extr=par1*4+par2*4+par3*4+par4*4+par5*4+par6*4+par7*4+par8*4;
                  extr1=par2*4+par3*4+par4*4+par5*4+par6*4+par7*4+par8*4;
                  extr2=par1*8+par2*8+par3*8+par4*8+par5*8+par6*8+par7*8+par8*8;
                  extr3=par1+par2+par3+par4+par5+par6+par7+par8;
                  extr4=extr4*16;
                  break;
        }

    }

}
u_int64_t Trie::getextr3(u_int64_t extr3)
{
    int count=extr3/256*256*256*2;
    if(extr3%256*256*256*2!=0)
         extr3=extr3-256*256*256*2*count;
    else
        extr3=0;
}

u_int64_t Trie::getextr4(u_int64_t extr3)
{
    int count=extr3/256*256*256*2*16*4;
    if(extr3%256*256*256*2*16*4!=0)
        extr3=extr3-256*256*256*2*16*4*count;
    else
        extr3=0;
}

u_int8_t Trie::setByte(int flagbit,u_int8_t bytee)
{
    switch(flagbit)
    {
        case 0:
            bytee=bytee | 0x80;
            break;
        case 1:
            bytee=bytee | 0x40;
            break;
        case 2:
            bytee=bytee | 0x20;
            break;
        case 3:
            bytee=bytee | 0x10;
            break;
        case 4:
            bytee=bytee | 0x08;
            break;
        case 5:
            bytee=bytee | 0x04;
            break;
        case 6:
            bytee=bytee | 0x02;
            break;
        case 7:
            bytee=bytee | 0x01;
            break;
    }
    return bytee;
}

u_int8_t Trie::getByte(int flagbit,u_int8_t bytee)
{
    switch(flagbit)
    {
        case 0:
        bytee=bytee & 0x80;
        bytee=bytee >> 7;
        break;
        case 1:
        bytee=bytee & 0x40;
        bytee=bytee >> 6;
        break;
        case 2:
        bytee=bytee & 0x20;
        bytee=bytee >> 5;
        break;
        case 3:
        bytee=bytee & 0x10;
        bytee=bytee >> 4;
        break;
        case 4:
        bytee=bytee & 0x08;
        bytee=bytee >> 3;
        break;
        case 5:
        bytee=bytee & 0x04;
        bytee=bytee >> 2;
        break;
        case 6:
        bytee=bytee & 0x02;
        bytee=bytee >> 1;
        break;
        case 7:
        bytee=bytee & 0x01;
        break;
    }
    return bytee;
}


u_int32_t Trie::getNode(const u_int32_t key) {
    u_int32_t bits = key;
    u_int32_t key1 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key2 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key3 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key4 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key5 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key6 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key7 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key8 = bits & 0x0000000F;
    vari1 = this->root;
    vari2 = this->firstlevel;
    u_int64_t cons = 1024;
    u_int32_t constantkey1 = key1;

    par1 = key1;
    extr = par1 * 4;
    extr2 = par1 * 8;
    extr3 = par1;
    extr4 = 2;
    for (int i = 0; i < 8; i++) {

        if (i < 6) {
            int flagbyte = extr3 / 8;
            int flagbit = extr3 % 8;

            u_int8_t bytee = *(u_int8_t *) (vari2 + cons + flagbyte);
            bytee = this->getByte(flagbit, bytee);
            if (bytee == 1) {
                if (*(u_int32_t *) (vari1 + extr) == extr * 16) { }
                else if(*(u_int32_t *) (vari1 + extr)==cons+extr2+extr4)// the case that bit flip has happened in the bytee
                {
                    u_int64_t  res=*(u_int64_t *)(vari2+cons+extr2+extr4);
                    //If key is the same as the key which is stored in this place then we will return the value otherwise, a bit flip has happened in the key
                    u_int64_t res2=res & 0xFFFFFFFF00000000;
                    u_int32_t res1=res2 >> 32;//key
                    if(res1==key) {
                        u_int32_t res1 = res & 0x00000000FFFFFFFF;
                        cout << "Bit flip has happened in the bytee and could be detected!!";
                        return res1;
                    }
                    else
                    {
                        cout<<"A bit flip has happened in the key itself!!";
                        return -1;
                    }
                }
                else {
                    cout << "Bit flip has happened, bit flip has happened in the pointer!!";
                    return -1;
                }
            }

            else {//bytee=0
                if(*(u_int32_t *) (vari1 + extr)==cons+extr2+extr4)
                {
                    u_int64_t  res=*(u_int64_t *)(vari2+cons+extr2+extr4);
                    u_int64_t res2=res & 0xFFFFFFFF00000000;
                    u_int32_t res1=res2 >> 32;//key
                    if(res1==key) {
                        u_int32_t res1 = res & 0x00000000FFFFFFFF;
                        return res1;
                    }
                    else
                    {
                        cout<<"A bit flip has happened in the key itself!!";
                        return -1;
                    }
                }
                 else if(*(u_int32_t *) (vari1 + extr)==extr*16)
                {
                    cout<<"Bit flip has happened in the bytee and could be detected!!";
                }
                else
                {
                   cout<<"A bit flip has happened in the pointer!!";
                    return -1;
                }
            }
        }
        else if (i == 6) {


            //at first we have to check if the node in the sublevel is set or not,so:
            cons = 256 * 256 * 256 * 16 * 8;
            int flagbyte = extr3 / 8;
            int flagbit = extr3 % 8;

            u_int8_t bytee = *(u_int8_t *) (vari2 + cons + flagbyte);
            bytee = this->getByte(flagbit, bytee);
            if (bytee == 1) {
                extr3=extr*16;
                extr3=this->getextr4(extr3);
                if (*(u_int32_t *) (vari1 + extr) ==extr3)
                {
                }
                else if(*(u_int32_t *) (vari1 + extr)==extr2)
                {
                    u_int64_t res=*(u_int64_t *)(this->extra+extr2);
                    u_int64_t res2=res & 0xFFFFFFFF00000000;
                    u_int32_t res1=res2 >> 32;//key
                    if(res1==key) {
                        u_int64_t res1 = res & 0x00000000FFFFFFFF;
                        cout << "Bit flip has happened in the bytee and could be detected!!";
                        return res1;
                    }
                    else{
                        cout<<"A bit flip has happened in the key itself!!";
                        return -1;
                    }
                }
                else
                {
                    cout<<"A bit flip has happened in the pointer!!";
                    return -1;
                }

            }

            else//bytee=0
            {
                if (*(u_int32_t *) (vari1 + extr) ==extr2)
                {
                    u_int64_t res=*(u_int64_t *)(this->extra+extr2);
                    u_int64_t res2=res & 0xFFFFFFFF00000000;
                    u_int32_t res1=res2 >> 32;//key
                    if(res1==key) {

                        u_int64_t res1 = res & 0x00000000FFFFFFFF;
                        return res1;
                    }
                    else{
                        cout<<"A bit flip has happened in the key itself!!";
                        return -1;
                    }
                }
                else if(*(u_int32_t *) (vari1 + extr) ==extr3)
                {
                    cout<<"Bit flip has happened in the bytee and could be detected!!";
                }
                else
                {
                    cout<<"A bit flip has happened in the pointer!!";
                    return -1;
                }
            }

        }
        else //i==7
        {

            extr = this->getextr4(extr);
            return *(u_int32_t *) (this->seventhlevel + extr);

        }

        switch (i) {
            case 0  :
                vari1 = this->firstlevel;
                vari2 = this->secondlevel;
                key1 = key1 * 16;
                par1 = key1;
                par2 = key2;
                cons = cons * 16;
                extr = par1 * 4 + par2 * 4;
                extr2 = par1 * 8 + par2 * 8;
                extr3 = par1 + par2;
                extr4 = extr4 * 16;
                break; //optional
            case 1  :
                vari1 = this->secondlevel;
                vari2 = this->thirdlevel;
                key1 = key1 * 16;
                key2 = key2 * 16;
                par1 = key1;
                par2 = key2;
                par3 = key3;
                cons = cons * 16;
                extr = par1 * 4 + par2 * 4 + par3 * 4;
                extr2 = par1 * 8 + par2 * 8 + par3 * 8;
                extr3 = par1 + par2 + par3;
                extr4 = extr4 * 16;
                break; //optional
            case 2  :
                vari1 = this->thirdlevel;
                vari2 = this->fourthlevel;
                key1 = key1 * 16;
                key2 = key2 * 16;
                key3 = key3 * 16;
                par1 = key1;
                par2 = key2;
                par3 = key3;
                par4 = key4;
                cons = cons * 16;
                extr = par1 * 4 + par2 * 4 + par3 * 4 + par4 * 4;
                extr2 = par1 * 8 + par2 * 8 + par3 * 8 + par4 * 8;
                extr3 = par1 + par2 + par3 + par4;
                extr4 = extr4 * 16;
                break;
            case 3  :
                vari1 = this->fourthlevel;
                vari2 = this->fifthlevel;
                key1 = key1 * 16;
                key2 = key2 * 16;
                key3 = key3 * 16;
                key4 = key4 * 16;
                par1 = key1;
                par2 = key2;
                par3 = key3;
                par4 = key4;
                par5 = key5;
                cons = cons * 16;
                extr = par1 * 4 + par2 * 4 + par3 * 4 + par4 * 4 + par5 * 4;
                extr2 = par1 * 8 + par2 * 8 + par3 * 8 + par4 * 8 + par5 * 8;
                extr3 = par1 + par2 + par3 + par4 + par5;
                extr4 = extr4 * 16;
                break;
            case 4  :
                vari1 = this->fifthlevel;
                vari2 = this->sixthlevel;
                key1 = key1 * 16;
                key2 = key2 * 16;
                key3 = key3 * 16;
                key4 = key4 * 16;
                key5 = key5 * 16;
                par1 = key1;
                par2 = key2;
                par3 = key3;
                par4 = key4;
                par5 = key5;
                par6 = key6;
                cons = cons * 16;
                extr = par1 * 4 + par2 * 4 + par3 * 4 + par4 * 4 + par5 * 4 + par6 * 4;
                extr2 = par1 * 8 + par2 * 8 + par3 * 8 + par4 * 8 + par5 * 8 + par6 * 8;
                extr3 = par1 + par2 + par3 + par4 + par5 + par6;
                extr4 = extr4 * 16;
                break;
            case 5  :
                vari1 = this->sixthlevel;
                key1 = key1 * 16;
                key2 = key2 * 16;
                key3 = key3 * 16;
                key4 = key4 * 16;
                key5 = key5 * 16;
                key6 = key6 * 16;
                par1 = key1;
                par2 = key2;
                par3 = key3;
                par4 = key4;
                par5 = key5;
                par6 = key6;
                par7 = key7;
                cons = cons * 16;
                if (constantkey1 < 2)
                    vari2 = this->seventhlevel;
                if (1 < constantkey1 and constantkey1 < 4)
                    vari2 = this->seven1level;

                if (3 < constantkey1 and constantkey1 < 6)
                    vari2 = this->seven2level;

                if (5 < constantkey1 and constantkey1 < 8)
                    vari2 = this->seven3level;

                if (7 < constantkey1 and constantkey1 < 10)
                    vari2 = this->seven4level;

                if (9 < constantkey1 and constantkey1 < 12)
                    vari2 = this->seven5level;

                if (11 < constantkey1 and constantkey1 < 14)
                    vari2 = this->seven6level;

                if (13 < constantkey1 and constantkey1 < 16)
                    vari2 = this->seven7level;

                extr = par1 * 4 + par2 * 4 + par3 * 4 + par4 * 4 + par5 * 4 + par6 * 4 + par7 * 4;
                extr1 = par2 * 4 + par3 * 4 + par4 * 4 + par5 * 4 + par6 * 4 + par7 * 4;
                extr2 = par1 * 8 + par2 * 8 + par3 * 8 + par4 * 8 + par5 * 8 + par6 * 8 + par7 * 8;
                extr3 = par1 + par2 + par3 + par4 + par5 + par6 + par7;
                extr4 = extr4 * 16;
                break;
            case 6  :
                key1 = key1 * 16;
                key2 = key2 * 16;
                key3 = key3 * 16;
                key4 = key4 * 16;
                key5 = key5 * 16;
                key6 = key6 * 16;
                key6 = key6 * 16;
                key7 = key7 * 16;
                par1 = key1;
                par2 = key2;
                par3 = key3;
                par4 = key4;
                par5 = key5;
                par6 = key6;
                par7 = key7;
                par8 = key8;
                cons = cons * 16;
                if (constantkey1 < 2)
                    vari2 = this->seventhlevel;
                if (1 < constantkey1 and constantkey1 < 4)
                    vari2 = this->seven1level;

                if (3 < constantkey1 and constantkey1 < 6)
                    vari2 = this->seven2level;

                if (5 < constantkey1 and constantkey1 < 8)
                    vari2 = this->seven3level;

                if (7 < constantkey1 and constantkey1 < 10)
                    vari2 = this->seven4level;

                if (9 < constantkey1 and constantkey1 < 12)
                    vari2 = this->seven5level;

                if (11 < constantkey1 and constantkey1 < 14)
                    vari2 = this->seven6level;

                if (13 < constantkey1 and constantkey1 < 16)
                    vari2 = this->seven7level;
                extr = par1 * 4 + par2 * 4 + par3 * 4 + par4 * 4 + par5 * 4 + par6 * 4 + par7 * 4 + par8 * 4;
                extr1 = par2 * 4 + par3 * 4 + par4 * 4 + par5 * 4 + par6 * 4 + par7 * 4 + par8 * 4;
                extr2 = par1 * 8 + par2 * 8 + par3 * 8 + par4 * 8 + par5 * 8 + par6 * 8 + par7 * 8 + par8 * 8;
                extr3 = par1 + par2 + par3 + par4 + par5 + par6 + par7 + par8;
                extr4 = extr4 * 16;
                break;

        }
    }
}

void Trie::setKeyValue() {
    /*u_int32_t bits = key;
    u_int32_t key1 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key2 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key3 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key4 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key5 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key6 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key7 = bits & 0x0000000F;
    bits = bits >> 4;
    u_int32_t key8 = bits & 0x0000000F;
    vari1 = this->root;
    vari2 = this->sixthlevel;
    u_int64_t cons = 1024;
    u_int32_t constantkey1 = key1;

    par1 = key1;
    extr = par1 * 4;
    extr2 = par1 * 8;
    extr3 = par1;
    extr4 = 2;*/

    //all the nodes in each sublevel: 256*256*256*2
    //256*256*256*2*16*4 :bytes of memory for a sublevel(just the nodes)
    //256*256*256*2/8: bytes of memory for flags in a sublevel
    //256*256*256*2/8 + 256*256*256*2*16*4 // all the bytes in a sublevel
    for(int i=0;i<2101248;i++)
    {
        vari2=this->seventhlevel;
        u_int8_t bytes=*(u_int8_t *)(vari2+i*1024);
        if(bytes!=0)
            cout<<"Byte was not zero!"<<endl;
        bytes=bytes ^ 0x01;
        *(u_int8_t *)(vari2+i*1024)=bytes;

    }
}


