/*
  youtube   = ImamID
  instagram = imamsbkti
*/
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

Adafruit_SSD1306 lcd(128, 64, &Wire, 4);

#define btnUp   7
#define btnOk   6
#define btnDown 5
#define btnBack 4

boolean statusBtnUp   = false;
boolean statusBtnOk   = false;
boolean statusBtnDown = false;
boolean statusBtnBack = false;

boolean statusAkhirBtnUp   = false;
boolean statusAkhirBtnOk   = false;
boolean statusAkhirBtnDown = false;
boolean statusAkhirBtnBack = false;

boolean UP   = false;
boolean OK   = false;
boolean DOWN = false;
boolean BACK = false;

int halaman  = 1;
int menuItem = 1;

void setup() {
  Serial.begin(115200);
  lcd.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  lcd.clearDisplay();

  pinMode(btnUp,   INPUT_PULLUP);
  pinMode(btnOk,   INPUT_PULLUP);
  pinMode(btnDown, INPUT_PULLUP);
  pinMode(btnBack, INPUT_PULLUP);
}

void loop() {
  tampil();

  statusBtnUp   = digitalRead(btnUp);
  statusBtnOk   = digitalRead(btnOk);
  statusBtnDown = digitalRead(btnDown);
  statusBtnBack = digitalRead(btnBack);

  saatUpDitekan();
  saatOkDitekan();
  saatDownDitekan();
  saatBackDitekan();

  //  untuk button up
  if (UP && halaman == 1) {
    UP = false;
    menuItem --;
    if (menuItem < 1)menuItem = 4;
  }
  //untuk button down
  if (DOWN && halaman == 1) {
    DOWN = false;
    menuItem ++;
    if (menuItem > 4)menuItem = 1;
  }

  //  untuk button ok
  if (OK) {
    OK = false;
    if (halaman == 1 && menuItem == 1) {
      halaman = 2;
    } else if (halaman == 1 && menuItem == 2) {
      halaman = 3;
    } else if (halaman == 1 && menuItem == 3) {
      halaman = 4;
    } else if (halaman == 1 && menuItem == 4) {
      halaman = 5;
    }
  }

  //  untuk button back
  if (BACK) {
    BACK = false;
    if (halaman == 2 || halaman == 3 || halaman == 4 || halaman == 5) {
      halaman = 1;
    }
  }

  Serial.println(menuItem);
  delay(100);
}

//--------------------------------------------------------------------------------
void saatUpDitekan() {
  if (statusBtnUp != statusAkhirBtnUp) {
    if (statusBtnUp == 0) {
      UP = true;
    }
    delay(50);
  }
  statusAkhirBtnUp = statusBtnUp;
}

void saatOkDitekan() {
  if (statusBtnOk != statusAkhirBtnOk) {
    if (statusBtnOk == 0) {
      OK = true;
    }
    delay(50);
  }
  statusAkhirBtnOk = statusBtnOk;
}

void saatDownDitekan() {
  if (statusBtnDown != statusAkhirBtnDown) {
    if (statusBtnDown == 0) {
      DOWN = true;
    }
    delay(50);
  }
  statusAkhirBtnDown = statusBtnDown;
}

void saatBackDitekan() {
  if (statusBtnBack != statusAkhirBtnBack) {
    if (statusBtnBack == 0) {
      BACK = true;
    }
    delay(50);
  }
  statusAkhirBtnBack = statusBtnBack;
}
//----------------------------------------------------------------------------

//semua yang tampil di lcd ada di fungsi ini
void tampil() {
  if (halaman == 1) {
    lcd.clearDisplay();
    lcd.setTextSize(1);
    lcd.setTextColor(WHITE);
    lcd.setCursor(30, 0);
    lcd.print("DAFTAR MENU");

    if (menuItem == 1) {
      lcd.setCursor(5, 17);
      lcd.setTextColor(WHITE);
      lcd.print("> menuItem 1");
    } else {
      lcd.setCursor(5, 17);
      lcd.setTextColor(WHITE);
      lcd.print("  menuItem 1");
    }

    if (menuItem == 2) {
      lcd.setCursor(5, 27);
      lcd.setTextColor(WHITE);
      lcd.print("> menuItem 2");
    } else {
      lcd.setCursor(5, 27);
      lcd.setTextColor(WHITE);
      lcd.print("  menuItem 2");
    }

    if (menuItem == 3) {
      lcd.setCursor(5, 37);
      lcd.setTextColor(WHITE);
      lcd.print("> menuItem 3");
    } else {
      lcd.setCursor(5, 37);
      lcd.setTextColor(WHITE);
      lcd.print("  menuItem 3");
    }

    if (menuItem == 4) {
      lcd.setCursor(5, 47);
      lcd.setTextColor(WHITE);
      lcd.print("> menuItem 4");
    } else {
      lcd.setCursor(5, 47);
      lcd.setTextColor(WHITE);
      lcd.print("  menuItem 4");
    }

  } else if (halaman == 2) {
    lcd.clearDisplay();
    lcd.setTextSize(2);
    lcd.setTextColor(WHITE);
    lcd.setCursor(25, 25);
    lcd.print("ImamID");
  } else if (halaman == 3) {
    lcd.clearDisplay();
    lcd.setTextSize(2);
    lcd.setTextColor(WHITE);
    lcd.setCursor(10, 15);
    lcd.print("SUBSCRIBE");
    lcd.setCursor(30, 35);
    lcd.print("ImamID");
  } else if (halaman == 4) {
    lcd.clearDisplay();
    lcd.setTextSize(2);
    lcd.setTextColor(WHITE);
    lcd.setCursor(25, 25);
    lcd.print("ini hal 4");
  } else if (halaman == 5) {
    lcd.clearDisplay();
    lcd.setTextSize(2);
    lcd.setTextColor(WHITE);
    lcd.setCursor(25, 25);
    lcd.print("ini hal 5");
  }

  lcd.display();
}
