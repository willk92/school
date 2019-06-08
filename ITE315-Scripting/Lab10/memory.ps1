param( [string]$computer = "." )

$free = ( Get-WMIObject Win32_OperatingSystem -ComputerName $computer ).FreePhysicalMemory * 1KB
$phys = ( Get-WMIObject Win32_OperatingSystem -ComputerName $computer ).TotalVisibleMemorySize * 1KB
if ( $computer -ne "." ) {
	Write-Host
	Write-Host "Computer: $computer"
}

# Table header
Write-Host
Write-Host "Physical memory".PadRight( 16, " " ) -NoNewline
Write-Host "Bytes".PadLeft( 14, " " ) -NoNewline
Write-Host "KB".PadLeft( 11, " " ) -NoNewline
Write-Host "MB".PadLeft( 8, " " )
Write-Host ( "=" * 49 )
# Table rows
Write-Host "Available".PadRight( 16, " " ) -NoNewline
Write-Host ([string]$free).PadLeft( 14, " " ) -NoNewline
Write-Host ([string][int]($free / 1KB)).PadLeft( 11, " " ) -NoNewline
Write-Host ([string][int]($free / 1MB)).PadLeft( 8, " " )
Write-Host "Total".PadRight( 16, " " ) -NoNewline
Write-Host ([string]$phys).PadLeft( 14, " " ) -NoNewline
Write-Host ([string][int]($phys / 1KB)).PadLeft( 11, " " ) -NoNewline
Write-Host ([string][int]($phys / 1MB)).PadLeft( 8, " " )
Write-Host