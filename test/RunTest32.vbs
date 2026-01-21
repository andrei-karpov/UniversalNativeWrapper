Option Explicit

If LCase(Right(WScript.FullName, 11)) = "wscript.exe" Then
    Dim shell
    Set shell = CreateObject("WScript.Shell")
    shell.Run "cscript //nologo """ & WScript.ScriptFullName & """", 1, True
    WScript.Quit 0
End If

WScript.Echo "Создание COM-объектов..."
Dim wrapper1, wrapper2
Set wrapper1 = CreateObject("Addin.UniversalNativeWrapper")
Set wrapper2 = CreateObject("Addin.UniversalNativeWrapper")
If wrapper1 Is Nothing Or wrapper2 Is Nothing Then
    WScript.Echo "Ошибка: COM-объекты не созданы."
    WScript.Quit 1
End If

Function BuildConnectionParameters()
    Dim lines
    lines = Array( _
        "<?xml version=""1.0"" encoding=""UTF-8""?>", _
        "<Parameters/>" _
    )
    BuildConnectionParameters = Join(lines, vbCrLf)
End Function

Function BuildInputParameters()
    Dim lines
    lines = Array( _
        "<?xml version=""1.0"" encoding=""UTF-8""?>", _
        "<InputParameters>", _
        "  <Parameters CashierName=""Иванов И.П."" CashierINN=""32456234523452"" PrintRequired=""false"" TimeSynchronization=""false""/>", _
        "</InputParameters>" _
    )
    BuildInputParameters = Join(lines, vbCrLf)
End Function

Function BuildCheckPackage()
    Dim lines
    lines = Array( _
        "<?xml version=""1.0"" encoding=""UTF-8""?>", _
        "<CheckPackage>", _
        "  <Parameters CashierName=""Иванов И.И"" OperationType=""1"" TaxationSystem=""0"" SaleAddress=""г.Москва, Дмитровское ш. д.9"" SaleLocation=""Торговый островок на 1 этаже"" GroupingPositionsWhenPrinting=""false"" CustomerEmail="""" CustomerPhone="""">", _
        "    <AgentData/>", _
        "    <VendorData/>", _
        "    <CustomerDetail/>", _
        "    <OperationalAttribute DateTime=""2024-10-31T13:24:24"" OperationID=""0"" OperationData=""DATA""/>", _
        "    <IndustryAttribute IdentifierFOIV=""001"" DocumentDate=""31.10.2024"" DocumentNumber=""2343243"" AttributeValue=""Ид1=Знач1&amp;Ид2=Знач2&amp;Ид3=Знач3""/>", _
        "  </Parameters>", _
        "  <Positions>", _
        "    <FiscalString Name=""Маркированный товар"" Quantity=""1"" PriceWithDiscount=""100"" AmountWithDiscount=""100"" DiscountAmount=""0"" Department=""3"" VATRate=""none"" PaymentMethod=""4"" CalculationSubject=""33"" MeasureOfQuantity=""0"">", _
        "      <AgentData/>", _
        "      <VendorData/>", _
        "      <IndustryAttribute IdentifierFOIV=""030"" DocumentDate=""21.11.2023"" DocumentNumber=""1944"" AttributeValue=""UUID=2ce10bdb-6510-4d37-be04-dd473b98c728&amp;Time=1692691702065""/>", _
        "    </FiscalString>", _
        "    <FiscalString Name=""Товар 3 Меховая шуба для проверки меха по сценарию ЦРПТ"" Quantity=""1"" PriceWithDiscount=""100"" AmountWithDiscount=""100"" DiscountAmount=""0"" Department=""1"" VATRate=""20"" VATAmount=""16.67"" PaymentMethod=""4"" CalculationSubject=""1"" MeasureOfQuantity=""0"">", _
        "      <GoodCodeData MI=""RU-430301-AAA0020659""/>", _
        "      <AgentData/>", _
        "      <VendorData/>", _
        "      <IndustryAttribute IdentifierFOIV=""030"" DocumentDate=""11.08.2016"" DocumentNumber=""787"" AttributeValue=""crpt=mrk""/>", _
        "    </FiscalString>", _
        "    <FiscalString Name=""Товар 4 Простой обычный товар весовой"" Quantity=""1"" PriceWithDiscount=""100"" AmountWithDiscount=""100"" DiscountAmount=""0"" Department=""3"" VATRate=""20"" VATAmount=""16.67"" PaymentMethod=""4"" CalculationSubject=""1"" MeasureOfQuantity=""11"">", _
        "      <AgentData/>", _
        "      <VendorData/>", _
        "      <IndustryAttribute/>", _
        "    </FiscalString>", _
        "  </Positions>", _
        "  <Payments Cash=""1000"" ElectronicPayment=""200"" PrePayment=""0"" PostPayment=""0"" Barter=""0""/>", _
        "  <ElectronicPaymentInfo>", _
        "    <ElectronicPayment Amount=""200"" PaymentMethod=""1"" Identifiers=""date=1626454200&amp;rrn=YJJJHHNNNNNN&amp;tid=12345678&amp;ps=22&amp;acq=12345678912&amp;auth=Z2Y22D"" AdditionalInformation=""uuid=1876876087657655""/>", _
        "  </ElectronicPaymentInfo>", _
        "</CheckPackage>" _
    )
    BuildCheckPackage = Join(lines, vbCrLf)
End Function

Sub CheckErr(stepName, wrapperObj)
    If Err.Number <> 0 Then
        WScript.Echo "Ошибка " & stepName & ": " & Err.Number & " " & Err.Description
        If Not (wrapperObj Is Nothing) Then
            Dim errDesc, errCode
            errDesc = ""
            On Error Resume Next
            errCode = wrapperObj.GetLastError(errDesc)
            On Error GoTo 0
            If errDesc <> "" Then
                WScript.Echo "GetLastError: " & errCode & " | " & errDesc
            End If
        End If
        Err.Clear
        WScript.Quit 2
    End If
End Sub

Function GetShiftState(outputXml)
    GetShiftState = ""
    If Len(outputXml) = 0 Then
        Exit Function
    End If
    Dim doc
    On Error Resume Next
    Set doc = CreateObject("MSXML2.DOMDocument.6.0")
    If doc Is Nothing Then
        Set doc = CreateObject("MSXML2.DOMDocument")
    End If
    On Error GoTo 0
    If doc Is Nothing Then
        Exit Function
    End If
    doc.async = False
    doc.validateOnParse = False
    If Not doc.loadXML(outputXml) Then
        Set doc = Nothing
        Exit Function
    End If
    Dim node
    Set node = doc.selectSingleNode("/OutputParameters/Parameters")
    If Not node Is Nothing Then
        GetShiftState = node.getAttribute("ShiftState")
    End If
    Set node = Nothing
    Set doc = Nothing
End Function

Dim fso
Dim basePath
Dim dllName
Dim result

WScript.Echo "Определение пути к каталогу test..."
Set fso = CreateObject("Scripting.FileSystemObject")
basePath = "C:\GIT\UniversalNativeWrapperNew\test\EmulatorKKTNativeWin32_5_2_4_4.dll"
dllName = "EmulatorKKT1C5"

WScript.Echo "setDriverName #1: " & basePath & " | " & dllName
On Error Resume Next
Call wrapper1.setDriverName(basePath, dllName)
Call CheckErr("setDriverName #1", wrapper1)
On Error GoTo 0
WScript.Echo "setDriverName #1: OK"

WScript.Echo "setDriverName #2: " & basePath & " | " & dllName
On Error Resume Next
Call wrapper2.setDriverName(basePath, dllName)
Call CheckErr("setDriverName #2", wrapper2)
On Error GoTo 0
WScript.Echo "setDriverName #2: OK"

WScript.Echo "Вызов GetInterfaceRevision #1..."
On Error Resume Next
result = wrapper1.GetInterfaceRevision()
Call CheckErr("GetInterfaceRevision #1", wrapper1)
On Error GoTo 0
WScript.Echo "Результат #1: " & result

WScript.Echo "Вызов GetInterfaceRevision #2..."
On Error Resume Next
result = wrapper2.GetInterfaceRevision()
Call CheckErr("GetInterfaceRevision #2", wrapper2)
On Error GoTo 0

WScript.Echo "Результат #2: " & result
WScript.Echo "Получение описания драйвера #1..."
Dim driverDesc
driverDesc = ""
On Error Resume Next
Call wrapper1.GetDescription(driverDesc)
Call CheckErr("GetDescription #1", wrapper1)
On Error GoTo 0
WScript.Echo "Описание драйвера #1 получено, длина: " & Len(driverDesc)

WScript.Echo "Получение описания драйвера #2..."
driverDesc = ""
On Error Resume Next
Call wrapper2.GetDescription(driverDesc)
Call CheckErr("GetDescription #2", wrapper2)
On Error GoTo 0
WScript.Echo "Описание драйвера #2 получено, длина: " & Len(driverDesc)

Dim equipmentType
equipmentType = "KKT"
WScript.Echo "Получение параметров оборудования (EquipmentParameters) #1..."
Dim tableParams
tableParams = ""
On Error Resume Next
Call wrapper1.EquipmentParameters(equipmentType, tableParams)
Call CheckErr("EquipmentParameters #1", wrapper1)
On Error GoTo 0
WScript.Echo "Параметры оборудования #1 получены, длина: " & Len(tableParams)

WScript.Echo "Получение параметров оборудования (EquipmentParameters) #2..."
tableParams = ""
On Error Resume Next
Call wrapper2.EquipmentParameters(equipmentType, tableParams)
Call CheckErr("EquipmentParameters #2", wrapper2)
On Error GoTo 0
WScript.Echo "Параметры оборудования #2 получены, длина: " & Len(tableParams)

WScript.Echo "Подключение оборудования (ConnectEquipment) #1..."
Dim deviceId1, deviceId2
deviceId1 = ""
Dim connectionParams
connectionParams = BuildConnectionParameters()
On Error Resume Next
Call wrapper1.ConnectEquipment(deviceId1, equipmentType, connectionParams)
Call CheckErr("ConnectEquipment #1", wrapper1)
On Error GoTo 0
WScript.Echo "DeviceID #1: " & deviceId1

WScript.Echo "Подключение оборудования (ConnectEquipment) #2..."
deviceId2 = ""
On Error Resume Next
Call wrapper2.ConnectEquipment(deviceId2, equipmentType, connectionParams)
Call CheckErr("ConnectEquipment #2", wrapper2)
On Error GoTo 0
WScript.Echo "DeviceID #2: " & deviceId2

WScript.Echo "Получение параметров ККТ (GetDataKKT) #1..."
Dim tableKkt
tableKkt = ""
On Error Resume Next
Call wrapper1.GetDataKKT(deviceId1, tableKkt)
Call CheckErr("GetDataKKT #1", wrapper1)
On Error GoTo 0
WScript.Echo "Параметры ККТ #1 получены, длина: " & Len(tableKkt)

WScript.Echo "Получение параметров ККТ (GetDataKKT) #2..."
tableKkt = ""
On Error Resume Next
Call wrapper2.GetDataKKT(deviceId2, tableKkt)
Call CheckErr("GetDataKKT #2", wrapper2)
On Error GoTo 0
WScript.Echo "Параметры ККТ #2 получены, длина: " & Len(tableKkt)

WScript.Echo "Открытие смены (OpenShift) #1..."
Dim inputParams
inputParams = BuildInputParameters()
Dim outputParams
outputParams = ""
On Error Resume Next
Call wrapper1.OpenShift(deviceId1, inputParams, outputParams)
Call CheckErr("OpenShift #1", wrapper1)
On Error GoTo 0
WScript.Echo "Выходные параметры OpenShift #1: " & outputParams

WScript.Echo "Открытие смены (OpenShift) #2..."
outputParams = ""
On Error Resume Next
Call wrapper2.OpenShift(deviceId2, inputParams, outputParams)
Call CheckErr("OpenShift #2", wrapper2)
On Error GoTo 0
WScript.Echo "Выходные параметры OpenShift #2: " & outputParams

WScript.Echo "Формирование чека (ProcessCheck) #1..."
Dim checkPackage
checkPackage = BuildCheckPackage()
Dim docOutput
docOutput = ""
On Error Resume Next
Call wrapper1.ProcessCheck(deviceId1, False, checkPackage, docOutput)
Call CheckErr("ProcessCheck #1", wrapper1)
On Error GoTo 0
WScript.Echo "Выходные параметры документа #1: " & docOutput

WScript.Echo "Формирование чека (ProcessCheck) #2..."
docOutput = ""
On Error Resume Next
Call wrapper2.ProcessCheck(deviceId2, False, checkPackage, docOutput)
Call CheckErr("ProcessCheck #2", wrapper2)
On Error GoTo 0
WScript.Echo "Выходные параметры документа #2: " & docOutput

WScript.Echo "Закрытие смены (CloseShift) только для #1..."
outputParams = ""
On Error Resume Next
Call wrapper1.CloseShift(deviceId1, inputParams, outputParams)
Call CheckErr("CloseShift #1", wrapper1)
On Error GoTo 0
WScript.Echo "Выходные параметры CloseShift #1: " & outputParams

WScript.Echo "Получение текущего состояния (GetCurrentStatus)..."
Dim statusOut1, statusOut2
statusOut1 = ""
statusOut2 = ""
On Error Resume Next
Call wrapper1.GetCurrentStatus(deviceId1, inputParams, statusOut1)
Call CheckErr("GetCurrentStatus #1", wrapper1)
Call wrapper2.GetCurrentStatus(deviceId2, inputParams, statusOut2)
Call CheckErr("GetCurrentStatus #2", wrapper2)
On Error GoTo 0
WScript.Echo "Выходные параметры состояния #1: " & statusOut1
WScript.Echo "Выходные параметры состояния #2: " & statusOut2

Dim shiftState1, shiftState2
shiftState1 = GetShiftState(statusOut1)
shiftState2 = GetShiftState(statusOut2)
WScript.Echo "ShiftState #1: " & shiftState1 & " (ожидается 1 - закрыта)"
WScript.Echo "ShiftState #2: " & shiftState2 & " (ожидается 2 - открыта)"

WScript.Echo "Отключение оборудования (DisconnectEquipment)..."
On Error Resume Next
Call wrapper1.DisconnectEquipment(deviceId1)
Call CheckErr("DisconnectEquipment #1", wrapper1)
Call wrapper2.DisconnectEquipment(deviceId2)
Call CheckErr("DisconnectEquipment #2", wrapper2)
On Error GoTo 0

WScript.Echo "Готово."
Set wrapper1 = Nothing
Set wrapper2 = Nothing
