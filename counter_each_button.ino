#include <M5Stack.h>

// 左ボタンのカウンタ
int left_btn_num = 0;
// 真ん中ボタンのカウンタ
int center_btn_num = 0;
// 右ボタンのカウンタ
int right_btn_num = 0;

// 棒グラフの幅
#define BAR_WIDTH 30
// カウンターを描画する高さ
#define COUNTER_HEIGHT 210
// 棒グラフ初期描画位置
#define BAR_HEIGHT COUNTER_HEIGHT-7
// ボタン1回押すあたりの係数
// 1にすると、MAXで200くらいまでカウントできる
// 3で66くらい
#define COUNT_UNIT 3

// 初期処理
void setup() {
  M5.begin();

  // 塗りつぶし
  M5.Lcd.fillRect(0,0,240,40,0);
  // 文字色と背景色の指定
  M5.Lcd.setTextColor(RED, BLACK);
  M5.Lcd.print("multi counter");
  
  // 文字の大きさの指定
  M5.Lcd.setTextSize(3);
}

void loop() {
  // 左のボタンを押したとき
  if (M5.BtnA.wasPressed()) {
    left_btn_num = left_btn_num + 1;
    M5.Lcd.setCursor(35, COUNTER_HEIGHT);
    M5.Lcd.println(left_btn_num);
    M5.Lcd.drawFastHLine(35, BAR_HEIGHT-left_btn_num*COUNT_UNIT, BAR_WIDTH, GREEN);
    M5.update();
  // 真ん中のボタンを押したとき
  } else if (M5.BtnB.wasPressed()) {
    center_btn_num = center_btn_num + 1;
    M5.Lcd.setCursor(130, COUNTER_HEIGHT);
    M5.Lcd.println(center_btn_num);
    M5.Lcd.drawFastHLine(130, BAR_HEIGHT-center_btn_num*COUNT_UNIT, BAR_WIDTH, GREEN);
    M5.update();
  // 右のボタンを押したとき
  } else if (M5.BtnC.wasPressed()) {
    right_btn_num = right_btn_num + 1;
    M5.Lcd.setCursor(226, COUNTER_HEIGHT);
    M5.Lcd.println(right_btn_num);
    M5.Lcd.drawFastHLine(226, BAR_HEIGHT-right_btn_num*COUNT_UNIT, BAR_WIDTH, GREEN);
    M5.update();
  }
  M5.update();
}
