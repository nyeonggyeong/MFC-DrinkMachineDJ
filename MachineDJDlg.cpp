
// MachineDJDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MachineDJ.h"
#include "MachineDJDlg.h"
#include "afxdialogex.h"
#include "mmsystem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMachineDJDlg 대화 상자



CMachineDJDlg::CMachineDJDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MACHINEDJ_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	//m_backBrush.CreateSolidBrush(RGB(25, 25, 25));
}

void CMachineDJDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_COLA, m_COLA);
	DDX_Control(pDX, IDC_LIST_MUSIC, m_list_music);
}

BEGIN_MESSAGE_MAP(CMachineDJDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_100, &CMachineDJDlg::OnBnClickedButton100)
	ON_BN_CLICKED(IDC_BUTTON_500, &CMachineDJDlg::OnBnClickedButton500)
	ON_BN_CLICKED(IDC_BUTTON_1000, &CMachineDJDlg::OnBnClickedButton1000)
	ON_BN_CLICKED(IDC_BUTTON_RETURN, &CMachineDJDlg::OnBnClickedButtonReturn)
	ON_BN_CLICKED(IDC_BUTTON_COLA, &CMachineDJDlg::OnBnClickedButtonCola)
	ON_BN_CLICKED(IDC_BUTTON_BUTTER, &CMachineDJDlg::OnBnClickedButtonButter)
	ON_BN_CLICKED(IDC_BUTTON_SOJU, &CMachineDJDlg::OnBnClickedButtonSoju)
	ON_BN_CLICKED(IDC_BUTTON_SHRIMP, &CMachineDJDlg::OnBnClickedButtonShrimp)
	ON_BN_CLICKED(IDC_BUTTON_MOGU, &CMachineDJDlg::OnBnClickedButtonMogu)
	ON_BN_CLICKED(IDC_BUTTON_BEER, &CMachineDJDlg::OnBnClickedButtonBeer)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, &CMachineDJDlg::OnBnClickedButtonLoad)
	ON_BN_CLICKED(IDC_BUTTON_PLAY, &CMachineDJDlg::OnBnClickedButtonPlay)
	ON_BN_CLICKED(IDC_BUTTON_5000, &CMachineDJDlg::OnBnClickedButton5000)
	ON_BN_CLICKED(IDC_BUTTON_10000, &CMachineDJDlg::OnBnClickedButton10000)
	ON_BN_CLICKED(IDC_BUTTON_OUT, &CMachineDJDlg::OnBnClickedButtonOut)
//	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CMachineDJDlg 메시지 처리기

BOOL CMachineDJDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMachineDJDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMachineDJDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);

		DrawDrink(dc, IDB_BITMAP1, 120, 90, 200, 200);  // 콜라
		DrawDrink(dc, IDB_BITMAP4, 430, 110, 230, 230);  // 버터링
		DrawDrink(dc, IDB_BITMAP6, 730, 100, 200, 200);  // 좋은데이
		DrawDrink(dc, IDB_BITMAP8, 110, 430, 200, 200);  // 매운새우깡
		DrawDrink(dc, IDB_BITMAP10, 430, 430, 200, 200);  // 모구모구
		DrawDrink(dc, IDB_BITMAP13, 760, 390, 300, 300);  // 테라

		if (m_Button_cola == 1) { // 콜라를 구매하였을 때
			DrawDrink(dc, IDB_BITMAP2, 120, 1150, 500, 500); // 해당 사진 출력
		}
		if (m_Button_butter == 1) { // 버터링을 구매하였을 때
			DrawDrink(dc, IDB_BITMAP3, 220, 1150, 500, 500); 
		}
		if (m_Button_soju == 1) { // 좋은데이를 구매하였을 때
			DrawDrink(dc, IDB_BITMAP5, 320, 1150, 500, 500);
		}
		if (m_Button_shrimp == 1) { // 매운 새우깡을 구매하였을 때
			DrawDrink(dc, IDB_BITMAP7, 420, 1150, 500, 500);
		}
		if (m_Button_mogu == 1) { // 모구모구 음료를 구매하였을 때
			DrawDrink(dc, IDB_BITMAP9, 620, 1150, 500, 500);
		}
		if (m_Button_beer == 1) { // 테라를 구매하였을 때
			DrawDrink(dc, IDB_BITMAP12, 850, 1150, 500, 500);
		}

		CDialogEx::OnPaint();

		CPen pen(PS_SOLID, 100, RGB(255, 175, 0)); // 선 스타일, 굵기, 색상 지정
		CPen* pOldPen = dc.SelectObject(&pen); // 새로 생성한 선을 선택

		// 첫 번째 선 그리기
		dc.MoveTo(0, 0);
		dc.LineTo(1030, 0);

		// 두 번째 선 그리기
		dc.MoveTo(0, 0);
		dc.LineTo(0, 1415);

		// 세 번째 선 그리기
		dc.MoveTo(1030, 0);
		dc.LineTo(1030, 1415);

		// 네 번째 선 그리기
		dc.MoveTo(0, 1415);
		dc.LineTo(1030, 1415);

		// 다섯 번째 선 그리기
		dc.MoveTo(0, 780);
		dc.LineTo(1030, 780);

		dc.MoveTo(0, 850);
		dc.LineTo(1030, 850);

		dc.MoveTo(0, 950);
		dc.LineTo(1030, 950);

		dc.MoveTo(0, 1020);
		dc.LineTo(1030, 1020);

		dc.SelectObject(pOldPen); // 이전에 선택한 선으로 복원
	}
}
void CMachineDJDlg::DrawDrink(CPaintDC& dc, int bitmapID, int x, int y, int width, int height)
{
	CBitmap bitmap;
	bitmap.LoadBitmap(bitmapID);

	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(&bitmap);
	dc.StretchBlt(x, y, width, height, &memDC, 0, 0, width, height, SRCCOPY);
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMachineDJDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMachineDJDlg::OnBnClickedButton100()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strAmount;
	GetDlgItemText(IDC_EDIT_RESULT, strAmount);
	int currentAmount = _ttoi(strAmount);

	// 새로운 금액 계산
	int newAmount = currentAmount + 100;

	// 계산된 금액을 Edit Control에 설정
	SetDlgItemInt(IDC_EDIT_RESULT, newAmount);
}


void CMachineDJDlg::OnBnClickedButton500()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strAmount;
	GetDlgItemText(IDC_EDIT_RESULT, strAmount);
	int currentAmount = _ttoi(strAmount);

	// 새로운 금액 계산
	int newAmount = currentAmount + 500;

	// 계산된 금액을 Edit Control에 설정
	SetDlgItemInt(IDC_EDIT_RESULT, newAmount);
}


void CMachineDJDlg::OnBnClickedButton1000()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strAmount;
	GetDlgItemText(IDC_EDIT_RESULT, strAmount);
	int currentAmount = _ttoi(strAmount);

	// 새로운 금액 계산
	int newAmount = currentAmount + 1000;

	// 계산된 금액을 Edit Control에 설정
	SetDlgItemInt(IDC_EDIT_RESULT, newAmount);
}

void CMachineDJDlg::OnBnClickedButton5000()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strAmount;
	GetDlgItemText(IDC_EDIT_RESULT, strAmount);
	int currentAmount = _ttoi(strAmount);

	// 새로운 금액 계산
	int newAmount = currentAmount + 5000;

	// 계산된 금액을 Edit Control에 설정
	SetDlgItemInt(IDC_EDIT_RESULT, newAmount);
}


void CMachineDJDlg::OnBnClickedButton10000()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strAmount;
	GetDlgItemText(IDC_EDIT_RESULT, strAmount);
	int currentAmount = _ttoi(strAmount);

	// 새로운 금액 계산
	int newAmount = currentAmount + 10000;

	// 계산된 금액을 Edit Control에 설정
	SetDlgItemInt(IDC_EDIT_RESULT, newAmount);
}

void CMachineDJDlg::OnBnClickedButtonReturn() // 돈을 반환해 주는 코드
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// Edit Control의 현재 돈 가져오기
	CString strAmount;
	GetDlgItemText(IDC_EDIT_RESULT, strAmount);
	int currentAmount = _ttoi(strAmount);

	SetDlgItemInt(IDC_EDIT_RESULT, 0); // Edit Control 초기화하여 돈 리셋함

	MessageBox(_T("돈을 반환하였습니다."));
}


void CMachineDJDlg::OnBnClickedButtonCola() // 콜라 버튼을 눌렀을 때
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	  // Edit Control의 현재 금액 가져오기
	CString strAmount;
	GetDlgItemText(IDC_EDIT_RESULT, strAmount);
	int currentAmount = _ttoi(strAmount);

	// 1000원 이상인 경우에만 콜라 구매 처리
	if (currentAmount >= 1000)
	{
		UpdateData(TRUE);

		currentAmount -= 1000; // Edit Control에서 1000원 차감

		SetDlgItemInt(IDC_EDIT_RESULT, currentAmount); // 차감된 금액을 Edit Control에 설정하여 화면에 반영
		UpdateData(FALSE);
		MessageBox(_T("구매 완료!"));
		m_Button_cola = 1;
		m_Button_conut = 1;
	}
	else
	{
		MessageBox(_T("돈이 부족합니다. 구매할 수 없습니다.")); // 구매 불가 메시지 출력
	}
	Invalidate();
}


void CMachineDJDlg::OnBnClickedButtonButter() // 버터링 버튼을 눌렀을 때
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strAmount;
	GetDlgItemText(IDC_EDIT_RESULT, strAmount);
	int currentAmount = _ttoi(strAmount);

	if (currentAmount >= 2100) // 2100원 이상인 경우에만 버터링 구매 가능
	{
		UpdateData(TRUE);

		currentAmount -= 2100; // Edit Control에서 2100원 차감됨

		SetDlgItemInt(IDC_EDIT_RESULT, currentAmount); // 차감된 금액을 Edit Control에 설정하여 화면에 반영
		UpdateData(FALSE);

		MessageBox(_T("구매 완료!")); // 구매 성공 메시지 출력
		m_Button_butter = 1;
		m_Button_conut = 1;
	}
	else
	{
		MessageBox(_T("돈이 부족합니다. 구매할 수 없습니다.")); // 구매 불가 메시지 출력
	}
	Invalidate();
}


void CMachineDJDlg::OnBnClickedButtonSoju() // 좋은데이 버튼을 눌렀을 때
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strAmount;
	GetDlgItemText(IDC_EDIT_RESULT, strAmount);
	int currentAmount = _ttoi(strAmount);

	if (currentAmount >= 4000) // 4000원 이상인 경우에만 콜라 구매 가능
	{
		UpdateData(TRUE);

		currentAmount -= 4000; // Edit Control에서 1000원 차감됨

		SetDlgItemInt(IDC_EDIT_RESULT, currentAmount); // 차감된 금액을 Edit Control에 설정하여 화면에 반영
		UpdateData(FALSE);

		MessageBox(_T("구매 완료!"));
		m_Button_soju = 1;
		m_Button_conut = 1;
	}
	else
	{
		MessageBox(_T("돈이 부족합니다. 구매할 수 없습니다.")); // 구매 불가 메시지 출력
	}
	Invalidate();
}


void CMachineDJDlg::OnBnClickedButtonShrimp() // 매운 새우깡 버튼을 눌렀을 때
{
	CString strAmount;
	GetDlgItemText(IDC_EDIT_RESULT, strAmount);
	int currentAmount = _ttoi(strAmount);

	
	if (currentAmount >= 1800) // 1800원 이상인 경우에만 매운 새우깡 구매 처리
	{
		UpdateData(TRUE);

		currentAmount -= 1800; // Edit Control에서 1800원 차감

		SetDlgItemInt(IDC_EDIT_RESULT, currentAmount); // 차감된 금액을 Edit Control에 설정하여 화면에 반영
		UpdateData(FALSE);

		MessageBox(_T("구매 완료!"));
		m_Button_shrimp = 1;
		m_Button_conut = 1;
	}
	else
	{
		MessageBox(_T("돈이 부족합니다. 구매할 수 없습니다.")); // 구매 불가 메시지 출력
	}
	Invalidate();
}


void CMachineDJDlg::OnBnClickedButtonMogu() // 모구모구 버튼을 눌렀을 때
{
	CString strAmount;
	GetDlgItemText(IDC_EDIT_RESULT, strAmount);
	int currentAmount = _ttoi(strAmount);

	if (currentAmount >= 1200) // 1200원 이상인 경우에만 모구모구 구매 처리
	{
		UpdateData(TRUE);

		currentAmount -= 1200; // Edit Control에서 1200원 차감

		SetDlgItemInt(IDC_EDIT_RESULT, currentAmount); // 차감된 금액을 Edit Control에 설정하여 화면에 반영
		UpdateData(FALSE);

		MessageBox(_T("구매 완료!"));
		m_Button_mogu = 1;
		m_Button_conut = 1;
	}
	else
	{
		MessageBox(_T("돈이 부족합니다. 구매할 수 없습니다.")); // 구매 불가 메시지 출력
	}
	Invalidate();
}


void CMachineDJDlg::OnBnClickedButtonBeer() // 테라 버튼을 눌렀을 때
{
	CString strAmount;
	GetDlgItemText(IDC_EDIT_RESULT, strAmount);
	int currentAmount = _ttoi(strAmount);

	if (currentAmount >= 3500) // 3500원 이상인 경우에만 테라 구매 처리
	{
		UpdateData(TRUE);

		currentAmount -= 3500; // Edit Control에서 3500원 차감

		SetDlgItemInt(IDC_EDIT_RESULT, currentAmount); // 차감된 금액을 Edit Control에 설정하여 화면에 반영
		UpdateData(FALSE);

		MessageBox(_T("구매 완료!"));
		m_Button_beer = 1;
		m_Button_conut = 1;
	}
	else
	{
		MessageBox(_T("돈이 부족합니다. 구매할 수 없습니다.")); // 구매 불가 메시지 출력
	}
	Invalidate();
}


void CMachineDJDlg::OnBnClickedButtonOut() // 상품 꺼내기 버튼을 누르면
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_Button_conut == 0) { // 나온 상품이 존재하지 않으면
		MessageBox(_T("나온 상품이 없습니다."));
	}
	else {
		m_Button_cola = 0;
		m_Button_butter = 0;
		m_Button_soju = 0;
		m_Button_shrimp = 0;
		m_Button_mogu = 0;
		m_Button_beer = 0;
		m_Button_conut = 0;
		MessageBox(_T("모든 상품을 꺼냈습니다."));
	}
	Invalidate();
}

////////////////////////////////////////////////////////////////////////////////////////////////
/* 여기서부터는 파일 선택 후 음악이 재생되는 기능 구현 부분 */

void CMachineDJDlg::OnBnClickedButtonLoad() // 노래 선택 버튼을 눌렀을 때
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_ALLOWMULTISELECT, _T("음악파일(*.wav;) | *.wav;||"), this); // 여러 개의 파일을 가져올 수 있게함
	TCHAR* pBuf = new TCHAR[MAX_PATH * 50];

	*pBuf = 0;
	dlg.m_ofn.lpstrFile = pBuf;
	dlg.m_ofn.nMaxFile = MAX_PATH * 50;

	if (dlg.DoModal() == IDOK) { // 만약에 파일 선택이 되었을 경우
		POSITION pos = dlg.GetStartPosition();
		CString strFile;
		while (pos != NULL) {
			strFile = dlg.GetNextPathName(pos); // 파일 이름 가져옴
			//CString fileNameOnly = PathFindFileName(strFile); // 파일 경로의 마지막을 가져옴

			//m_list_music.AddString(strFile);
			//m_list_music.AddString(fileNameOnly); // 리스트 박스에 파일 추가

			m_list_music.AddString(strFile); // 리스트 박스에 전체 파일 경로 추가
		}
	}
	delete[] pBuf; // 파일 탐색기 버퍼 비움
}

void CMachineDJDlg::OnBnClickedButtonPlay() // 노래 듣기 버튼을 눌렀을 때
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strCmd;
	DWORD dwErr;
	int nIndex = m_list_music.GetCurSel();
	if (nIndex < 0)
		return;
	m_list_music.GetText(nIndex, m_szFullName);
	GetShortPathName(m_szFullName, m_szShortName, MAX_PATH);

	if (m_bPlaying) { // 이미 재생 중인 경우
		strCmd.Format(_T("stop %s"), m_szShortName); // 노래를 멈추게함
		dwErr = mciSendString(strCmd, NULL, 0, NULL);
		m_bPlaying = FALSE;
	}
	else { // 재생 중이 아닌 경우
		strCmd.Format(_T("open %s"), m_szShortName); // 노래 파일을 열고
		dwErr = mciSendString(strCmd, NULL, 0, NULL);

		strCmd.Format(_T("play %s"), m_szShortName); // 노래 재생 시킴
		dwErr = mciSendString(strCmd, NULL, 0, NULL);
		m_bPlaying = TRUE;
	}
}


//HBRUSH CMachineDJDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
//{
//	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
//
	// 그룹 박스의 ID를 확인
//	if (pWnd->GetDlgCtrlID() == IDC_GROUP2)
//	{
		// 배경을 흰색으로 설정
//		pDC->SetBkColor(RGB(255, 255, 255));
//
		// 배경을 그리기 위해 커스텀 그리기를 수행
//		CBrush brush(RGB(255, 255, 255));
//		return (HBRUSH)brush.GetSafeHandle();
//	}
//
	// 다른 컨트롤들의 색상 처리
//	if (m_backBrush.GetSafeHandle() == nullptr) {
//		m_backBrush.CreateSolidBrush(RGB(255, 0, 0)); // 빨간색 브러시 객체 생성
//	}
//
//	pDC->SetTextColor(RGB(255, 255, 255));
//	pDC->SetBkColor(RGB(255, 0, 0)); // 빨간색 배경색 설정
//	pDC->SetBkMode(TRANSPARENT);
//	hbr = (HBRUSH)m_backBrush;
//
//	return hbr;
//
//}



