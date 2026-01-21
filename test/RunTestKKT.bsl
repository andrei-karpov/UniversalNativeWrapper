Процедура RunTestKKT() Экспорт
	Попытка
		Сообщить("Создание COM-объектов...");
		Обертка1 = Новый COMОбъект("Addin.UniversalNativeWrapper");
		Обертка2 = Новый COMОбъект("Addin.UniversalNativeWrapper");
	Исключение
		Сообщить("Ошибка создания COM-объектов: " + ОписаниеОшибки());
		Возврат;
	КонецПопытки;

	ПутьКDLL = "C:\GIT\UniversalNativeWrapperNew\test\EmulatorKKTNativeWin64_5_2_4_4.dll";
	ИмяКласса = "EmulatorKKT1C5";

	Если Не ВызватьSetDriverName(Обертка1, ПутьКDLL, ИмяКласса, "#1") Тогда Возврат;
	Если Не ВызватьSetDriverName(Обертка2, ПутьКDLL, ИмяКласса, "#2") Тогда Возврат;

	ОборудованиеТип = "KKT";
	ПараметрыПодключения = ПостроитьПараметрыПодключения();
	ВходныеПараметры = ПостроитьВходныеПараметры();
	ПакетЧека = ПостроитьПакетЧека();

	Если Не ПодключитьОборудование(Обертка1, ОборудованиеТип, ПараметрыПодключения, " #1") Тогда Возврат;
	Если Не ПодключитьОборудование(Обертка2, ОборудованиеТип, ПараметрыПодключения, " #2") Тогда Возврат;

	Если Не ОткрытьСмену(Обертка1, ВходныеПараметры, " #1") Тогда Возврат;
	Если Не ОткрытьСмену(Обертка2, ВходныеПараметры, " #2") Тогда Возврат;

	Если Не СформироватьЧек(Обертка1, ПакетЧека, " #1") Тогда Возврат;
	Если Не СформироватьЧек(Обертка2, ПакетЧека, " #2") Тогда Возврат;

	Если Не ЗакрытьСмену(Обертка1, ВходныеПараметры, " #1") Тогда Возврат;

	Статус1 = ПолучитьСостояние(Обертка1, ВходныеПараметры, " #1");
	Статус2 = ПолучитьСостояние(Обертка2, ВходныеПараметры, " #2");

	Смена1 = ПолучитьShiftState(Статус1);
	Смена2 = ПолучитьShiftState(Статус2);
	Сообщить("ShiftState #1: " + Смена1 + " (ожидается 1 - закрыта)");
	Сообщить("ShiftState #2: " + Смена2 + " (ожидается 2 - открыта)");

	ОтключитьОборудование(Обертка1, " #1");
	ОтключитьОборудование(Обертка2, " #2");
	
	Сообщить("Готово.");
КонецПроцедуры

Функция ВызватьSetDriverName(Обертка, ПутьКDLL, ИмяКласса, Метка) Экспорт
	Попытка
		Сообщить("setDriverName" + Метка + ": " + ПутьКDLL + " | " + ИмяКласса);
		Обертка.setDriverName(ПутьКDLL, ИмяКласса);
		Сообщить("setDriverName" + Метка + ": OK");
		Возврат Истина;
	Исключение
		Сообщить("Ошибка setDriverName" + Метка + ": " + ОписаниеОшибки());
		Возврат Ложь;
	КонецПопытки;
КонецФункции

Функция ПодключитьОборудование(Обертка, ОборудованиеТип, ПараметрыПодключения, Метка) Экспорт
	Попытка
		Сообщить("ConnectEquipment" + Метка + "...");
		Идентификатор = "";
		Обертка.ConnectEquipment(Идентификатор, ОборудованиеТип, ПараметрыПодключения);
		Сообщить("DeviceID" + Метка + ": " + Идентификатор);
		Обертка.DeviceID = Идентификатор;
		Возврат Истина;
	Исключение
		Сообщить("Ошибка ConnectEquipment" + Метка + ": " + ОписаниеОшибки());
		Возврат Ложь;
	КонецПопытки;
КонецФункции

Функция ОткрытьСмену(Обертка, ВходныеПараметры, Метка) Экспорт
	Попытка
		Сообщить("OpenShift" + Метка + "...");
		ВыходныеПараметры = "";
		Обертка.OpenShift(Обертка.DeviceID, ВходныеПараметры, ВыходныеПараметры);
		Сообщить("OpenShift" + Метка + " OK");
		Возврат Истина;
	Исключение
		Сообщить("Ошибка OpenShift" + Метка + ": " + ОписаниеОшибки());
		Возврат Ложь;
	КонецПопытки;
КонецФункции

Функция СформироватьЧек(Обертка, ПакетЧека, Метка) Экспорт
	Попытка
		Сообщить("ProcessCheck" + Метка + "...");
		ВыходныеПараметрыДокумента = "";
		Обертка.ProcessCheck(Обертка.DeviceID, Ложь, ПакетЧека, ВыходныеПараметрыДокумента);
		Сообщить("ProcessCheck" + Метка + " OK");
		Возврат Истина;
	Исключение
		Сообщить("Ошибка ProcessCheck" + Метка + ": " + ОписаниеОшибки());
		Возврат Ложь;
	КонецПопытки;
КонецФункции

Функция ЗакрытьСмену(Обертка, ВходныеПараметры, Метка) Экспорт
	Попытка
		Сообщить("CloseShift" + Метка + "...");
		ВыходныеПараметры = "";
		Обертка.CloseShift(Обертка.DeviceID, ВходныеПараметры, ВыходныеПараметры);
		Сообщить("CloseShift" + Метка + " OK");
		Возврат Истина;
	Исключение
		Сообщить("Ошибка CloseShift" + Метка + ": " + ОписаниеОшибки());
		Возврат Ложь;
	КонецПопытки;
КонецФункции

Функция ПолучитьСостояние(Обертка, ВходныеПараметры, Метка) Экспорт
	Попытка
		Сообщить("GetCurrentStatus" + Метка + "...");
		ВыходныеПараметры = "";
		Обертка.GetCurrentStatus(Обертка.DeviceID, ВходныеПараметры, ВыходныеПараметры);
		Возврат ВыходныеПараметры;
	Исключение
		Сообщить("Ошибка GetCurrentStatus" + Метка + ": " + ОписаниеОшибки());
		Возврат "";
	КонецПопытки;
КонецФункции

Процедура ОтключитьОборудование(Обертка, Метка) Экспорт
	Попытка
		Сообщить("DisconnectEquipment" + Метка + "...");
		Обертка.DisconnectEquipment(Обертка.DeviceID);
		Сообщить("DisconnectEquipment" + Метка + " OK");
	Исключение
		Сообщить("Ошибка DisconnectEquipment" + Метка + ": " + ОписаниеОшибки());
	КонецПопытки;
КонецПроцедуры

Функция ПолучитьShiftState(ВыходныеПараметры) Экспорт
	Если ПустаяСтрока(ВыходныеПараметры) Тогда
		Возврат "";
	КонецЕсли;
	Попытка
		Док = Новый XMLДокумент;
		Док.ПрочитатьСтроку(ВыходныеПараметры);
		Узел = Док.НайтиПоИмени("OutputParameters");
		Если Узел = Неопределено Тогда
			Возврат "";
		КонецЕсли;
		Параметры = Узел.НайтиПоИмени("Parameters");
		Если Параметры = Неопределено Тогда
			Возврат "";
		КонецЕсли;
		Возврат Параметры.Атрибуты.ShiftState;
	Исключение
		Возврат "";
	КонецПопытки;
КонецФункции

Функция ПостроитьПараметрыПодключения() Экспорт
	Возврат "<?xml version=""1.0"" encoding=""UTF-8""?>
|<Parameters/>";
КонецФункции

Функция ПостроитьВходныеПараметры() Экспорт
	Возврат "<?xml version=""1.0"" encoding=""UTF-8""?>
|<InputParameters>
|  <Parameters CashierName=""Иванов И.П."" CashierINN=""32456234523452"" PrintRequired=""false"" TimeSynchronization=""false""/>
|</InputParameters>";
КонецФункции

Функция ПостроитьПакетЧека() Экспорт
	Возврат "<?xml version=""1.0"" encoding=""UTF-8""?>
|<CheckPackage>
|  <Parameters CashierName=""Иванов И.И"" OperationType=""1"" TaxationSystem=""0"" SaleAddress=""г.Москва, Дмитровское ш. д.9"" SaleLocation=""Торговый островок на 1 этаже"" GroupingPositionsWhenPrinting=""false"" CustomerEmail="""" CustomerPhone="""">
|    <AgentData/>
|    <VendorData/>
|    <CustomerDetail/>
|    <OperationalAttribute DateTime=""2024-10-31T13:24:24"" OperationID=""0"" OperationData=""DATA""/>
|    <IndustryAttribute IdentifierFOIV=""001"" DocumentDate=""31.10.2024"" DocumentNumber=""2343243"" AttributeValue=""Ид1=Знач1&amp;Ид2=Знач2&amp;Ид3=Знач3""/>
|  </Parameters>
|  <Positions>
|    <FiscalString Name=""Маркированный товар"" Quantity=""1"" PriceWithDiscount=""100"" AmountWithDiscount=""100"" DiscountAmount=""0"" Department=""3"" VATRate=""none"" PaymentMethod=""4"" CalculationSubject=""33"" MeasureOfQuantity=""0"">
|      <AgentData/>
|      <VendorData/>
|      <IndustryAttribute IdentifierFOIV=""030"" DocumentDate=""21.11.2023"" DocumentNumber=""1944"" AttributeValue=""UUID=2ce10bdb-6510-4d37-be04-dd473b98c728&amp;Time=1692691702065""/>
|    </FiscalString>
|    <FiscalString Name=""Товар 3 Меховая шуба для проверки меха по сценарию ЦРПТ"" Quantity=""1"" PriceWithDiscount=""100"" AmountWithDiscount=""100"" DiscountAmount=""0"" Department=""1"" VATRate=""20"" VATAmount=""16.67"" PaymentMethod=""4"" CalculationSubject=""1"" MeasureOfQuantity=""0"">
|      <GoodCodeData MI=""RU-430301-AAA0020659""/>
|      <AgentData/>
|      <VendorData/>
|      <IndustryAttribute IdentifierFOIV=""030"" DocumentDate=""11.08.2016"" DocumentNumber=""787"" AttributeValue=""crpt=mrk""/>
|    </FiscalString>
|    <FiscalString Name=""Товар 4 Простой обычный товар весовой"" Quantity=""1"" PriceWithDiscount=""100"" AmountWithDiscount=""100"" DiscountAmount=""0"" Department=""3"" VATRate=""20"" VATAmount=""16.67"" PaymentMethod=""4"" CalculationSubject=""1"" MeasureOfQuantity=""11"">
|      <AgentData/>
|      <VendorData/>
|      <IndustryAttribute/>
|    </FiscalString>
|  </Positions>
|  <Payments Cash=""1000"" ElectronicPayment=""200"" PrePayment=""0"" PostPayment=""0"" Barter=""0""/>
|  <ElectronicPaymentInfo>
|    <ElectronicPayment Amount=""200"" PaymentMethod=""1"" Identifiers=""date=1626454200&amp;rrn=YJJJHHNNNNNN&amp;tid=12345678&amp;ps=22&amp;acq=12345678912&amp;auth=Z2Y22D"" AdditionalInformation=""uuid=1876876087657655""/>
|  </ElectronicPaymentInfo>
|</CheckPackage>";
КонецФункции
