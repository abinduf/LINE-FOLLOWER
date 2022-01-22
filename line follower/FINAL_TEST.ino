const int en_a_left =11;
const int in_1_left =12;
const int in_2_left =13;
const int en_b_right =10;
const int in_3_right =8;
const int in_4_right =7;

void forward(int pwmleft , int pwmright)
{
  digitalWrite(in_1_left,HIGH);
  digitalWrite(in_2_left,LOW);
  analogWrite(en_a_left,pwmleft);
  digitalWrite(in_3_right,HIGH);
  digitalWrite(in_4_right,LOW);
  analogWrite(en_b_right,pwmright);
}
void backward(int pwmleft , int pwmright)
{
  digitalWrite(in_1_left,LOW);
  digitalWrite(in_2_left,HIGH);
  analogWrite(en_a_left,pwmleft);
  digitalWrite(in_3_right,LOW);
  digitalWrite(in_4_right,HIGH);
  analogWrite(en_b_right,pwmright);
}

void left(int pwmleft , int pwmright)
{
  digitalWrite(in_1_left,HIGH);
  digitalWrite(in_2_left,LOW);
  analogWrite(en_a_left,pwmleft);
  digitalWrite(in_3_right,LOW);
  digitalWrite(in_4_right,HIGH);
  analogWrite(en_b_right,pwmright);
}

void right(int pwmleft , int pwmright)
{
  digitalWrite(in_1_left,LOW);
  digitalWrite(in_2_left,HIGH);
  analogWrite(en_a_left,pwmleft);
  digitalWrite(in_3_right,HIGH);
  digitalWrite(in_4_right,LOW);
  analogWrite(en_b_right,pwmright);
}

void stopp()
{
  digitalWrite(in_1_left,LOW);
  digitalWrite(in_2_left,LOW);
  analogWrite(en_a_left,0);
  digitalWrite(in_3_right,HIGH);
  digitalWrite(in_4_right,HIGH);
  analogWrite(en_b_right,0);
}

const int ldr1 = A2;
const int ldr2 = A1;
const int ldr3 = A0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(en_a_left,OUTPUT);
pinMode(in_1_left,OUTPUT);
pinMode(in_2_left,OUTPUT);
pinMode(en_b_right,OUTPUT);
pinMode(in_3_right,OUTPUT);
pinMode(in_4_right,OUTPUT);

pinMode(ldr1,INPUT);
pinMode(ldr2,INPUT);
pinMode(ldr3,INPUT);
}

void loop() {
  int ldrval_1=analogRead(ldr1);
  int ldrval_2=analogRead(ldr2);
  int ldrval_3=analogRead(ldr3);

int memory;

Serial.print(ldrval_1);
Serial.print("\t");
Serial.print(ldrval_2);
Serial.print("\t");
Serial.print(ldrval_3);
Serial.println("\t");

  if(ldrval_1 >= 100 && ldrval_2<=90 && ldrval_3>=100)
  {
    
    forward(80,80);
  }
  else if(ldrval_1 >= 100 && ldrval_2>=90 && ldrval_3<=90 )
  {
    
    right(0,75);
    memory=1;
  }
  else if(ldrval_1 <= 90 && ldrval_2>=100 && ldrval_3>=100)
  {
    
    left(75,0);
    memory=2;
    
  }else if(ldrval_1 >=100 && ldrval_2<=90 && ldrval_3<=100 )
  {
    right(0,75);
    memory=1;
  }
  else if(ldrval_1 <= 90 && ldrval_2<=90 && ldrval_3>=100)
  {
    left(75,0);
    memory=2;
  }
  
  else
    {
      switch(memory)
      {
        case 1:right(0,75);break;
        case 2:left(75,0);break;
        default:break;
      }
    }
}
