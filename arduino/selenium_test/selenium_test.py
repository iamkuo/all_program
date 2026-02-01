from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from webdriver_manager.chrome import ChromeDriverManager
import time
import gspread
from oauth2client.service_account import ServiceAccountCredentials
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

def get_all_links(driver, url):
    driver.get(url)
    
    all_links = set()
    
    while True:
        try:
            # 等待頁面加載
            WebDriverWait(driver, 10).until(
                EC.presence_of_element_located((By.TAG_NAME, 'a'))
            )
            
            # 獲取當前頁面所有的 URL
            links = driver.find_elements(By.TAG_NAME, 'a')
            for link in links:
                href = link.get_attribute('href')
                if href:
                    all_links.add(href)
            
            # 嘗試找到並點擊「下一頁」按鈕
            try:
                next_button = driver.find_element(By.CSS_SELECTOR, 'a.pagination-next')
                if next_button:
                    next_button.click()
                    WebDriverWait(driver, 10).until(
                        EC.staleness_of(next_button)  # 等待頁面加載完成
                    )
                else:
                    break
            except Exception as e:
                print(f"未找到下一頁按鈕或其他錯誤: {e}")
                break
        except Exception as e:
            print(f"处理过程中发生错误: {e}")
            break
    
    return all_links

def find_product_info_and_title(driver, url):
    driver.get(url)
    time.sleep(5)  # 等待页面加载

    # 获取页面的HTML原始码
    page_source = driver.page_source

    # 查找 <title> 标签所在的行
    title_line = "找不到 <title> 标签"
    if '<title>' in page_source:
        title_line = page_source.split('<title>')[1].split('</title>')[0].strip()

    # 查找被欣赏次数
    likes = "找不到被欣賞次数的元素"
    if '被欣賞' in page_source:
        likes = page_source.split('被欣賞')[1].split('<')[0].strip()

    # 查找价格
    price = "找不到价格元素"
    if 'NT$' in page_source:
        price = page_source.split('NT$')[1].split('<')[0].strip()

    # 查找人收藏
    favorites = "找不到人收藏"
    if '人收藏' in page_source:
        favorites = page_source.split('人收藏')[0].split('共')[1].strip()

    # 查找已卖出
    sold = "沒賣出"  # 默认值
    if '已賣出' in page_source:
        sold = page_source.split('已賣出')[1].split('<')[0].strip()

    # 查找剩最后或件以上
    stock = "<10"  # 默认值
    if '剩最後' in page_source:
        stock = page_source.split('剩最後')[1].split('<')[0].strip()
    elif '件以上' in page_source:
        stock = page_source.split('件以上')[1].split('<')[0].strip()

    return {
        "title": title_line,
        "price": price,
        "likes": likes,
        "sold": sold,
        "favorites": favorites,
        "stock": stock
    }

def update_google_sheet(row, product_info):
    # 使用您的凭证文件
    scope = ["https://spreadsheets.google.com/feeds", "https://www.googleapis.com/auth/spreadsheets",
             "https://www.googleapis.com/auth/drive.file", "https://www.googleapis.com/auth/drive"]
    creds = ServiceAccountCredentials.from_json_keyfile_name("C:/Yang2/py/credentials.json", scope)
    client = gspread.authorize(creds)

    # 打开 Google 试算表
    spreadsheet = client.open_by_url('https://docs.google.com/spreadsheets/d/1dhzisIIN1DlNTPhCIl6W5lKvlGD3PrJRJs8EJGs5QIs/edit?gid=0#gid=0')
    worksheet = spreadsheet.get_worksheet(0)  # 选择第一个工作表

    # 将数据写入 Google 试算表的指定位置
    worksheet.update(f'B{row}', [[product_info['title']]])
    worksheet.update(f'C{row}', [[product_info['price']]])
    worksheet.update(f'D{row}', [[product_info['likes']]])
    worksheet.update(f'E{row}', [[product_info['sold']]])
    worksheet.update(f'F{row}', [[product_info['favorites']]])
    worksheet.update(f'G{row}', [[product_info['stock']]])

def main():
    options = Options()
    options.add_argument("--headless")

    driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=options)
    
    # 使用你的凭证文件
    scope = ["https://spreadsheets.google.com/feeds", "https://www.googleapis.com/auth/spreadsheets",
             "https://www.googleapis.com/auth/drive.file", "https://www.googleapis.com/auth/drive"]
    creds = ServiceAccountCredentials.from_json_keyfile_name("C:/Yang2/py/credentials.json", scope)
    client = gspread.authorize(creds)
    idx = 2
    # 打开 Google 试算表
    spreadsheet = client.open_by_url('https://docs.google.com/spreadsheets/d/1dhzisIIN1DlNTPhCIl6W5lKvlGD3PrJRJs8EJGs5QIs/edit?gid=0#gid=0')
    worksheet = spreadsheet.get_worksheet(0)  # 选择第一个工作表
    if(int(input("請問要更新商店URL嗎?是:1否:0"))):
        all_links = get_all_links(driver,input("請輸入商店URL:"))
        for i in all_links:
            worksheet.update(f'A{idx}', i)
            idx += 1

    # 从第二行开始遍历每一行的URL
    row = 2
    while True:
        url = worksheet.cell(row, 1).value
        if not url:
            break  # 如果没有新的URL，退出循环

        try:
            product_info = find_product_info_and_title(driver, url)
            print(f"处理行 {row} 的商品信息:")
            print("被欣賞次数:", product_info["likes"])
            print("价格:", product_info["price"])
            print("人收藏:", product_info["favorites"])
            print("已賣出:", product_info["sold"])
            print("剩最後:", product_info["stock"])
            print("网页的<title>内容:", product_info["title"])
            
            # 更新Google试算表
            update_google_sheet(row, product_info)

            print(f"数据已成功写入第 {row} 行！")

        except Exception as e:
            print(f"发生错误: {e}")
        
        # 处理完一行后，继续到下一行
        row += 1

    driver.quit()

if __name__ == "__main__":
    main()