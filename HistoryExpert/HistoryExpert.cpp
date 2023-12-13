
#include "framework.h"
#include "HistoryExpert.h"
#include "MillenniumRepo.h"
#include "CenturyRepo.h"

#define MAX_LOADSTRING 100

#define IDC_BUTTON_FIRST_MILLENNIUM  5001
#define IDC_BUTTON_SECOND_MILLENNIUM 5002
#define IDC_BUTTIN_UPDATE 5003

HWND hFirstMillennium, hSecondMillennium, hEditorButton;
HWND hButton1, hButton2, hButton3;
HWND hList1, hList2, hEdit1;
HWND hButtonAdd, hButtonDel, hButtonEditor;
HWND hListBox, hEditBox;

TCHAR Millennium[100];
auto repo = std::make_unique<MillenniumRepo>("Millennium.txt");
auto crepo = std::make_unique<CenturyRepo>("Century.txt");

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    dlgProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    updateProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_HISTORYEXPERT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_HISTORYEXPERT));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_HISTORYEXPERT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_HISTORYEXPERT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        MoveWindow(hWnd, 300, 150, 505, 300, true);
        SetWindowText(hWnd, L"History Expert");

        hFirstMillennium = CreateWindowEx(0, L"BUTTON", L"First Millennium", WS_CHILD |
            WS_VISIBLE, 20, 20, 145, 40, hWnd, (HMENU)IDC_BUTTON_FIRST_MILLENNIUM,
            hInst, NULL);
        hSecondMillennium = CreateWindowEx(0, L"BUTTON", L"Second Millennium", WS_CHILD |
            WS_VISIBLE, 170, 20, 145, 40, hWnd, (HMENU)IDC_BUTTON_SECOND_MILLENNIUM,
            hInst, NULL);
        hEditorButton = CreateWindowEx(0, L"BUTTON", L"Editor", WS_CHILD |
                WS_VISIBLE, 20, 100, 290, 40, hWnd, (HMENU)IDC_BUTTIN_UPDATE,
                hInst, NULL);
        
    }
    break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDC_BUTTON_FIRST_MILLENNIUM:
            {
                lstrcpy(Millennium, L"First Millenium");
                DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, dlgProc);
            }
                break;
            case IDC_BUTTON_SECOND_MILLENNIUM:
            {
                lstrcpy(Millennium, L"Second Millenium");
                DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, dlgProc);
            }
                break;
            case IDC_BUTTIN_UPDATE:
            {
                DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, updateProc);
            }
                break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
    {
    }
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK dlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
    {
        TCHAR buff[100];
        lstrcpy(buff, L"Інформаційне вікно - ");
        lstrcat(buff, Millennium);
        SetWindowText(hDlg, buff);

        // 2
        hList1 = GetDlgItem(hDlg, IDC_LIST2);
        hList2 = GetDlgItem(hDlg, IDC_LIST3);
        hEdit1 = GetDlgItem(hDlg, IDC_EDIT1);

    }
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

INT_PTR CALLBACK updateProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
    {
        hButtonAdd = GetDlgItem(hDlg, IDC_BUTTON1);
        hButtonDel = GetDlgItem(hDlg, IDC_BUTTON2);
        hButtonEditor = GetDlgItem(hDlg, IDC_BUTTON3);
        hListBox = GetDlgItem(hDlg, IDC_LIST1);
        hEditBox = GetDlgItem(hDlg, IDC_EDIT1);

        repo->loadData();
        for (auto& m : repo->getMillennium()) {
            SendMessage(hListBox, LB_ADDSTRING, 0, LPARAM(m.getName()));
            

        }
    }
    return (INT_PTR)TRUE;

    case WM_COMMAND:
        int wmId = LOWORD(wParam);
        if (wmId == IDC_BUTTON1) {
            TCHAR buff[100];
            GetWindowText(hEditBox, buff, 100);

            if (lstrlen(buff) == 0) {
                MessageBox(hDlg, L"Ви не ввели назву нового регіону", L"Попередження", MB_OK | MB_ICONWARNING);
                SetFocus(hEditBox);
            }
            else {
                
            }
            
        }
        else if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}



