<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="11008008">
	<Item Name="Mein Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">Mein Computer/VI-Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">Mein Computer/VI-Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="SubVIs" Type="Folder">
			<Item Name="Axis_Switch.ctl" Type="VI" URL="../SubVIs/Axis_Switch.ctl"/>
			<Item Name="AxisControl.ctl" Type="VI" URL="../SubVIs/AxisControl.ctl"/>
			<Item Name="CheckLimitSwitches.vi" Type="VI" URL="../SubVIs/CheckLimitSwitches.vi"/>
			<Item Name="Connect.vi" Type="VI" URL="../SubVIs/Connect.vi"/>
			<Item Name="DequeueWithParameters.vi" Type="VI" URL="../SubVIs/DequeueWithParameters.vi"/>
			<Item Name="DialogSpeed.vi" Type="VI" URL="../SubVIs/DialogSpeed.vi"/>
			<Item Name="Disconnect.vi" Type="VI" URL="../SubVIs/Disconnect.vi"/>
			<Item Name="FindTANGOPort.vi" Type="VI" URL="../SubVIs/FindTANGOPort.vi"/>
			<Item Name="GetAnalogOutValues.vi" Type="VI" URL="../SubVIs/GetAnalogOutValues.vi"/>
			<Item Name="Maeander_Param.ctl" Type="VI" URL="../SubVIs/Maeander_Param.ctl"/>
			<Item Name="MaeanderDemo.vi" Type="VI" URL="../SubVIs/MaeanderDemo.vi"/>
			<Item Name="MaeanderDemo_Dlg.vi" Type="VI" URL="../SubVIs/MaeanderDemo_Dlg.vi"/>
			<Item Name="SequenceDemo.vi" Type="VI" URL="../SubVIs/SequenceDemo.vi"/>
			<Item Name="SequenceDemo_dlg.vi" Type="VI" URL="../SubVIs/SequenceDemo_dlg.vi"/>
			<Item Name="SequenceParam.ctl" Type="VI" URL="../SubVIs/SequenceParam.ctl"/>
			<Item Name="Timout_Operations.vi" Type="VI" URL="../SubVIs/Timout_Operations.vi"/>
		</Item>
		<Item Name="MW_neu.ico" Type="Document" URL="../MW_neu.ico"/>
		<Item Name="TANGO_Example_LV2011.vi" Type="VI" URL="../TANGO_Example_LV2011.vi"/>
		<Item Name="Abhängigkeiten" Type="Dependencies">
			<Item Name="user.lib" Type="Folder">
				<Item Name="Tango_DLL.lvlib" Type="Library" URL="/&lt;userlib&gt;/Tango_DLL/Tango_DLL.lvlib"/>
			</Item>
			<Item Name="vi.lib" Type="Folder">
				<Item Name="Space Constant.vi" Type="VI" URL="/&lt;vilib&gt;/dlg_ctls.llb/Space Constant.vi"/>
				<Item Name="VISA Find Search Mode.ctl" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Find Search Mode.ctl"/>
			</Item>
		</Item>
		<Item Name="Build-Spezifikationen" Type="Build">
			<Item Name="TANGO_Example_LV2011" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{E80AA296-E345-4A57-8208-ECA2993BBAEE}</Property>
				<Property Name="App_INI_GUID" Type="Str">{30D0D596-51DF-43F2-BD2B-51E2FC77D94F}</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{C4A38624-333F-4141-A8BD-FABC941FDE0F}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">TANGO_Example_LV2011</Property>
				<Property Name="Bld_defaultLanguage" Type="Str">German</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../builds/NI_AB_PROJECTNAME/TANGO_Example_LV2011</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToCommon</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{D79B2AA4-43D3-4779-A6E4-CE0FB3EEEED8}</Property>
				<Property Name="Destination[0].destName" Type="Str">TANGO_Example_LV2011.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../builds/NI_AB_PROJECTNAME/TANGO_Example_LV2011/TANGO_Example_LV2011.exe</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Hilfsdatei-Verzeichnis</Property>
				<Property Name="Destination[1].path" Type="Path">../builds/NI_AB_PROJECTNAME/TANGO_Example_LV2011/data</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Exe_iconItemID" Type="Ref"></Property>
				<Property Name="Source[0].itemID" Type="Str">{1CDB911A-7EC8-48B7-BF3A-767606714447}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/Mein Computer/TANGO_Example_LV2011.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">Märzhäuser Sensotech GmbH</Property>
				<Property Name="TgtF_fileDescription" Type="Str">TANGO_Example_LV2011</Property>
				<Property Name="TgtF_fileVersion.major" Type="Int">1</Property>
				<Property Name="TgtF_internalName" Type="Str">TANGO_Example_LV2011</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2013 Märzhäuser Sensotech GmbH</Property>
				<Property Name="TgtF_productName" Type="Str">TANGO_Example_LV2011</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{93687EC6-2FA4-4019-83D2-0B3534965B7C}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">TANGO_Example_LV2011.exe</Property>
			</Item>
		</Item>
	</Item>
</Project>
