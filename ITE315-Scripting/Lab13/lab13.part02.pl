#!/usr/bin/perl

# File: lab13.part02.pl
# William Kelley

use 5.010;
use strict;
use warnings;

open (my $pass, "/etc/passwd");
open (my $sortout, "| sort -n");

while (my $user = <$pass>) {
  my @row = split (/:/, $user);
  # print $sortout "$row[2] $row[0]";
  if ($row[2] >= 100) {
    print $sortout "$row[2] $row[0]\n";
  }
}

# 200 _softwareupdate
# 202 _coreaudiod
# 203 _screensaver
# 205 _locationd
# 208 _trustevaluationagent
# 210 _timezone
# 211 _lda
# 212 _cvmsroot
# 213 _usbmuxd
# 214 _dovecot
# 215 _dpaudio
# 216 _postgres
# 217 _krbtgt
# 218 _kadmin_admin
# 219 _kadmin_changepw
# 220 _devicemgr
# 221 _webauthserver
# 222 _netbios
# 224 _warmd
# 227 _dovenull
# 228 _netstatistics
# 229 _avbdeviced
# 230 _krb_krbtgt
# 231 _krb_kadmin
# 232 _krb_changepw
# 233 _krb_kerberos
# 234 _krb_anonymous
# 235 _assetcache
# 236 _coremediaiod
# 239 _launchservicesd
# 240 _iconservices
# 241 _distnote
# 242 _nsurlsessiond
# 243 _nsurlstoraged
# 244 _displaypolicyd
# 245 _astris
# 246 _krbfast
# 247 _gamecontrollerd
# 248 _mbsetupuser
# 249 _ondemand
# 251 _xserverdocs
# 252 _wwwproxy
# 253 _mobileasset
# 254 _findmydevice
# 257 _datadetectors
# 258 _captiveagent
# 259 _ctkd
# 260 _applepay
# 261 _hidd
# 262 _cmiodalassistants
# 263 _analyticsd
# 265 _fpsd
# 266 _timed
# 269 _reportmemoryexception