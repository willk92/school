#Display  week number of specific date or if none entered display current week

if ( $args -ne "" ) {
    $day = [DateTime]"$args"
    [decimal]$day_number = $day.DayOfYear
    $week_number = [Math]::Round([Math]::Ceiling($day_number/7))
    Write-Host $week_number
}
else {
    Get-Date -UFormat %V
}