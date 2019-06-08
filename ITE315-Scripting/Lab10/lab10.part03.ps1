param ( [string]$arg = "" )

if ( ( $arg -ne "" ) -or ( $HOME[0] -eq "/" ) ) {
  Write-Host
  Write-Host "BootState.ps1, Version 1.00"
  Write-Host "Show Windows' bootstate"
  Write-Host
  Write-Host "Usage:    PowerShell  . 'BootState.ps1'"
  Write-Host
  Write-Host "Notes:    Boot State is returned as string and as return code (`"errorlevel`"):"
  Write-Host "`"Normal`" (errorlevel = 0)"
  Write-Host "`"Safe mode`" (errorlevel = 1)"
  Write-Host "`"Safe mode with network`" (errorlevel=2)"
  Write-Host "`"Windows PE`" (errorlevel=3)"
  Write-Host "In case of (command line) errors, the errorlevel will be -1."
  Write-Host "This script is written for Windows only."
  exit -1
}

if ( Test-Path "HKLM:\SYSTEM\ControlSet001\Control\MiniNT" ) {
    Write-Host "Windows PE"
}

foreach ( $computer in Get-WmiObject -Class Win32_ComputerSystem ) {
    switch ( $computer.BootupState ) {
        "Normal boot" {
            Write-Host "Normal"
            exit 0
        }
        "Fail-safe boot" {
            Write-Host "Safe mode"
            exit 1
        }
        "Fail-safe with network boot" {
            Write-Host "Safe mode with network"
            exit 2
        }
    }
}

Write-Host "Unknown"
exit -1